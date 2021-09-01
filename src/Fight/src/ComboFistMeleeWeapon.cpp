/*!
 * \file ComboFistMeleeWeapon.cpp
 */

#include "ComboFistMeleeWeapon.h"

#include "Languages.h"
#include "Selection.h"
#include "WeaponFistCombo.h"

ComboFistMeleeWeapon::ComboFistMeleeWeapon(Player* const player)
    : Combo(player, data::Combo::titleFistMeleeWeapon,
            data::Combo::triggerStatementFistMeleeWeapon,
            data::Combo::triggeredStatementFistMeleeWeapon,
            data::Combo::malusStatementFistMeleeWeapon) {}

void ComboFistMeleeWeapon::triggerCombo(
    Plug* const plug, const int& resultChooseWeapon,
    const std::vector<UseWeapon*>& useWeapon) {
  // if the player has attack with his fist, trigger the combo
  // and the ennemy is not dead
  // and player has at least one melee weapon
  if (useWeapon[resultChooseWeapon]->weapon()->weaponType() ==
          WeaponType::fist &&
      !(plug->dead()) &&
      player_->weapons()->containWeaponType(WeaponType::meleeWeapon)) {
    // Build vector of useWeapon actions without the fist action
    std::vector<const Weapon*> weaponFistComboVector;

    for (std::size_t i = 0; i < useWeapon.size(); i++) {
      // Generate combo weapon, if the weapon is a melee weapon
      if (useWeapon[i]->weapon()->weaponType() == WeaponType::meleeWeapon) {
        const Weapon* weaponFistCombo =
            new WeaponFistCombo(useWeapon[i]->weapon());
        weaponFistComboVector.push_back(weaponFistCombo);
      }
    }

    std::vector<Action*> useWeaponFistCombo;

    for (std::size_t i = 0; i < weaponFistComboVector.size(); i++) {
      useWeaponFistCombo.push_back(new UseWeapon(
          player_, plug, weaponFistComboVector[i],
          data::Weapon::resultUseWeapon(
              plug->name(), weaponFistComboVector[i]->damageWeapon())));
    }

    std::vector<std::string> statements;
    std::transform(useWeaponFistCombo.cbegin(), useWeaponFistCombo.cend(),
                   std::back_inserter(statements),
                   [](auto action) { return action->statement(); });

    auto result = Select::select(data::Combo::titleFistMeleeWeapon, statements);

    useWeaponFistCombo[result]->triggerAction();

    for (std::size_t i = 0; i < weaponFistComboVector.size(); i++) {
      delete weaponFistComboVector[i];
    }

    for (std::size_t i = 0; i < useWeaponFistCombo.size(); i++) {
      delete useWeaponFistCombo[i];
    }
  }
}