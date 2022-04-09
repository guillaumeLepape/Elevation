#ifndef COMBO_QUADRUPLE_CUTTER_H
#define COMBO_QUADRUPLE_CUTTER_H

#include "combo.h"

template <utils::Printable T> class ComboQuadrupleCutter : public Combo<T> {
 public:
  ComboQuadrupleCutter(entity::Player& player)
      : Combo<T>{player, data::combo::titleQuadrupleCutter,
                 data::combo::triggerStatementQuadrupleCutter,
                 data::combo::triggeredStatementQuadrupleCutter,
                 data::combo::malusStatementQuadrupleCutter} {}

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