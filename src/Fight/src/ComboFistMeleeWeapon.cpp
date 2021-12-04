/*!
 * \file ComboFistMeleeWeapon.cpp
 */

#include "ComboFistMeleeWeapon.h"

#include "Languages.h"
#include "SelectionWrapper.h"

ComboFistMeleeWeapon::ComboFistMeleeWeapon(Player& player)
    : Combo(player, data::Combo::titleFistMeleeWeapon,
            data::Combo::triggerStatementFistMeleeWeapon,
            data::Combo::triggeredStatementFistMeleeWeapon,
            data::Combo::malusStatementFistMeleeWeapon) {}

void ComboFistMeleeWeapon::triggerCombo(
    Plug& plug, const int& resultChooseWeapon,
    const std::vector<UseWeapon>& useWeapon) {
  // if the player has attack with his fist, trigger the combo
  // and the ennemy is not dead
  // and player has at least one melee weapon
  if (useWeapon[resultChooseWeapon].type() == weapon::Type::fist &&
      !(plug.healthBar().dead()) &&
      weapon::contains(player_.weapons(), weapon::Type::meleeWeapon)) {
    std::vector<UseWeapon> useWeaponFistCombo;

    for (auto weapon = std::cbegin(player_.weapons());
         weapon != std::cend(player_.weapons()); ++weapon) {
      if (weapon->type == weapon::Type::meleeWeapon) {
        useWeaponFistCombo.push_back(UseWeapon(player_, plug, weapon->name));
      }
    }

    SelectionWrapper::select(title_, useWeaponFistCombo);
  }
}