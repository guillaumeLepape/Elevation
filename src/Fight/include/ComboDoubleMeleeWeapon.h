#ifndef COMBO_DOUBLE_MELEE_WEAPON
#define COMBO_DOUBLE_MELEE_WEAPON

/*!
 * \file ComboDoubleMeleeWeapon.h
 */

#include "Combo.h"

class ComboDoubleMeleeWeapon : public Combo {
 public:
  ComboDoubleMeleeWeapon(entity::Player& player);

  void triggerCombo(entity::Plug& plug, const int& resultChooseWeapon,
                    const std::vector<action::UseWeapon>& useWeapon) override;

  ~ComboDoubleMeleeWeapon() override = default;
};

#endif