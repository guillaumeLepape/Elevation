#pragma once

#include "elevation/action/nothing.h"
#include "elevation/action/use_weapon.h"
#include "elevation/fight/combo.h"
#include "elevation/selection/selection.h"

namespace elevation {
template <utils::Printable T>
class ComboDoubleMeleeWeapon : public Combo<T> {
 public:
  ComboDoubleMeleeWeapon(entity::Player& player)
      : Combo<T>{player, data::combo::titleDoubleMeleeWeapon,
                 data::combo::triggerStatementDoubleMeleeWeapon,
                 data::combo::triggeredStatementDoubleMeleeWeapon,
                 data::combo::malusStatementDoubleMeleeWeapon} {}

  void triggerCombo(entity::Plug& plug, action::UseWeapon& useWeapon) override {
    if ((useWeapon.name() == data::weapon::nameKnife or
         useWeapon.name() == data::weapon::nameHammer) and
        plug.healthBar().alive()) {
      auto result = selection::select(
          Combo<T>::title_,
          action::UseWeapon{Combo<T>::player_, plug, useWeapon.name()},
          action::Nothing{data::combo::statementDontCombo});
      if (result == 0) {
        weapon::remove(Combo<T>::player_.weapons(), useWeapon.name());
      }
    }
  }

  ~ComboDoubleMeleeWeapon() override = default;
};
}  // namespace elevation
