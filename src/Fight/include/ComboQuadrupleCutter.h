#ifndef COMBO_QUADRUPLE_CUTTER_H
#define COMBO_QUADRUPLE_CUTTER_H

/*!
 * \file ComboQuadrupleCutter.h
 */

#include "Combo.h"

class ComboQuadrupleCutter : public Combo {
 public:
  ComboQuadrupleCutter(Player* const player);

  void triggerCombo(Plug* const plug, const int& resultChooseWeapon,
                    const std::vector<UseWeapon>& useWeapon) override;

  ~ComboQuadrupleCutter() override = default;
};

#endif