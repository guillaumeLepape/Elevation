#pragma once

#include "elevation/fight/combo.h"

namespace elevation {
template <utils::Printable T>
class ComboQuadrupleCutter : public Combo<T> {
 public:
  ComboQuadrupleCutter(entity::Player& player)
      : Combo<T>{player, data::combo::titleQuadrupleCutter,
                 data::combo::triggerStatementQuadrupleCutter,
                 data::combo::triggeredStatementQuadrupleCutter,
                 data::combo::malusStatementQuadrupleCutter} {}

  void triggerCombo(entity::Plug&, action::UseWeapon& useWeapon) override {
    if (useWeapon.name() == "Cutter") {
      useWeapon.trigger();
      useWeapon.trigger();
      useWeapon.trigger();
      weapon::remove(Combo<T>::player_.weapons(), useWeapon.name());
    }
  }

  ~ComboQuadrupleCutter() override = default;
};
}  // namespace elevation
