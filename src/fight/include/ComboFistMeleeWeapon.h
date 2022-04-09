#ifndef COMBO_FIST_MELEE_WEAPON_H
#define COMBO_FIST_MELEE_WEAPON_H

#include "Combo.h"

template <utils::Printable T> class ComboFistMeleeWeapon : public Combo<T> {
 public:
  ComboFistMeleeWeapon(entity::Player& player)
      : Combo<T>{player, data::combo::titleFistMeleeWeapon,
                 data::combo::triggerStatementFistMeleeWeapon,
                 data::combo::triggeredStatementFistMeleeWeapon,
                 data::combo::malusStatementFistMeleeWeapon} {}

  void triggerCombo(entity::Plug& plug, int resultChooseWeapon,
                    const std::vector<action::UseWeapon>& useWeapon) override {
    // if the player has attack with his fist, trigger the combo
    // and the ennemy is not dead
    // and player has at least one melee weapon
    if (useWeapon[resultChooseWeapon].type() == weapon::Type::fist and
        plug.healthBar().alive() and
        weapon::contains(Combo<T>::player_.weapons(),
                         weapon::Type::meleeWeapon)) {
      std::vector<action::UseWeapon> useWeaponFistCombo;

      for (auto weapon = std::cbegin(Combo<T>::player_.weapons());
           weapon != std::cend(Combo<T>::player_.weapons()); ++weapon) {
        if (weapon->type == weapon::Type::meleeWeapon) {
          useWeaponFistCombo.push_back(
              action::UseWeapon{Combo<T>::player_, plug, weapon->name});
        }
      }

      selection::select(Combo<T>::title_, useWeaponFistCombo);
    }
  }
  ~ComboFistMeleeWeapon() override = default;
};

#endif