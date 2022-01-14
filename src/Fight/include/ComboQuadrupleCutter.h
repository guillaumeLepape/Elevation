#ifndef COMBO_QUADRUPLE_CUTTER_H
#define COMBO_QUADRUPLE_CUTTER_H

#include "Combo.h"

class ComboQuadrupleCutter : public Combo {
 public:
  ComboQuadrupleCutter(entity::Player& player);

  void triggerCombo(entity::Plug& plug, const int& resultChooseWeapon,
                    const std::vector<action::UseWeapon>& useWeapon) override;

  ~ComboQuadrupleCutter() override = default;
};

#endif