#ifndef COMBO_QUADRUPLE_CUTTER_H
#define COMBO_QUADRUPLE_CUTTER_H

#include "Combo.h"

template <utils::Printable T> class ComboQuadrupleCutter : public Combo<T> {
 public:
  ComboQuadrupleCutter(entity::Player& player)
      : Combo<T>{player, data::Combo::titleQuadrupleCutter,
                 data::Combo::triggerStatementQuadrupleCutter,
                 data::Combo::triggeredStatementQuadrupleCutter,
                 data::Combo::malusStatementQuadrupleCutter} {}

  void triggerCombo(entity::Plug&, int resultChooseWeapon,
                    const std::vector<action::UseWeapon>& useWeapon) override {
    if (useWeapon[resultChooseWeapon].name() == "Cutter") {
      action::UseWeapon useWeaponCombo = useWeapon[resultChooseWeapon];

      useWeaponCombo.trigger();
      useWeaponCombo.trigger();
      useWeaponCombo.trigger();
      weapon::remove(Combo<T>::player_.weapons(),
                     useWeapon[resultChooseWeapon].name());
    }
  }

  ~ComboQuadrupleCutter() override = default;
};

#endif