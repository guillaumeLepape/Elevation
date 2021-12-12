#ifndef COMBO_FIST_MELEE_WEAPON_H
#define COMBO_FIST_MELEE_WEAPON_H

/*!
 * \file ComboFistMeleeWeapon.h
 */

#include "Combo.h"

class ComboFistMeleeWeapon : public Combo {
 public:
  ComboFistMeleeWeapon(entity::Player& player);

  void triggerCombo(entity::Plug& plug, const int& resultChooseWeapon,
                    const std::vector<action::UseWeapon>& useWeapon) override;

  ~ComboFistMeleeWeapon() override = default;
};

#endif