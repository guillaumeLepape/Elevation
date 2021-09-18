#ifndef COMBO_FIST_MELEE_WEAPON_H
#define COMBO_FIST_MELEE_WEAPON_H

/*!
 * \file ComboFistMeleeWeapon.h
 */

#include "Combo.h"

class ComboFistMeleeWeapon : public Combo {
 public:
  ComboFistMeleeWeapon(Player& player);

  void triggerCombo(Plug& plug, const int& resultChooseWeapon,
                    const std::vector<UseWeapon>& useWeapon) override;

  ~ComboFistMeleeWeapon() override = default;
};

#endif