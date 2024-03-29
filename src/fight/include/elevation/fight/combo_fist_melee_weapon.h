#pragma once

#include "elevation/fight/combo.h"

namespace elevation {
template <utils::Printable T>
class ComboFistMeleeWeapon : public Combo<T> {
 public:
  ComboFistMeleeWeapon(entity::Player& player)
      : Combo<T>{player, data::combo::titleFistMeleeWeapon,
                 data::combo::triggerStatementFistMeleeWeapon,
                 data::combo::triggeredStatementFistMeleeWeapon,
                 data::combo::malusStatementFistMeleeWeapon} {}

  void triggerCombo(entity::Plug& plug, action::UseWeapon& useWeapon) override {
    // if the player has attack with his fist, trigger the combo
    // and the ennemy is not dead
    // and player has at least one melee weapon
    if (useWeapon.type() == weapon::Type::fist and plug.healthBar().alive() and
        weapon::contains(Combo<T>::player_.weapons(),
                         weapon::Type::meleeWeapon)) {
      std::vector<action::UseWeapon> useWeaponFistCombo;

      for (const auto& weapon : Combo<T>::player_.weapons()) {
        if (weapon.type == weapon::Type::meleeWeapon) {
          useWeaponFistCombo.push_back(
              action::UseWeapon{Combo<T>::player_, plug, weapon.name});
        }
      }

      selection::select(Combo<T>::title_, useWeaponFistCombo);
    }
  }
  ~ComboFistMeleeWeapon() override = default;
};
}  // namespace elevation
