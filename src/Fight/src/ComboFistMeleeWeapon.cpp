#include "ComboFistMeleeWeapon.h"

#include "Languages.h"
#include "Selection.h"

ComboFistMeleeWeapon::ComboFistMeleeWeapon(entity::Player& player)
    : Combo{player, data::Combo::titleFistMeleeWeapon,
            data::Combo::triggerStatementFistMeleeWeapon,
            data::Combo::triggeredStatementFistMeleeWeapon,
            data::Combo::malusStatementFistMeleeWeapon} {}

void ComboFistMeleeWeapon::triggerCombo(
    entity::Plug& plug, int resultChooseWeapon,
    const std::vector<action::UseWeapon>& useWeapon) {
  // if the player has attack with his fist, trigger the combo
  // and the ennemy is not dead
  // and player has at least one melee weapon
  if (useWeapon[resultChooseWeapon].type() == weapon::Type::fist and
      plug.healthBar().alive() and
      weapon::contains(player_.weapons(), weapon::Type::meleeWeapon)) {
    std::vector<action::UseWeapon> useWeaponFistCombo;

    for (auto weapon = std::cbegin(player_.weapons());
         weapon != std::cend(player_.weapons()); ++weapon) {
      if (weapon->type == weapon::Type::meleeWeapon) {
        useWeaponFistCombo.push_back(
            action::UseWeapon{player_, plug, weapon->name});
      }
    }

    selection::select(title_, useWeaponFistCombo);
  }
}