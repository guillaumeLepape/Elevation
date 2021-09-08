#ifndef COMBO_DOUBLE_MELEE_WEAPON
#define COMBO_DOUBLE_MELEE_WEAPON

/*!
 * \file ComboDoubleMeleeWeapon.h
 */

#include "Combo.h"

class ComboDoubleMeleeWeapon : public Combo {
 public:
  ComboDoubleMeleeWeapon(Player* const player);

  void triggerCombo(Plug* const plug, const int& resultChooseWeapon,
                    const std::vector<UseWeapon>& useWeapon) override;

  ~ComboDoubleMeleeWeapon() override = default;
};

#endif