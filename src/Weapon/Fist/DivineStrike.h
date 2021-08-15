#ifndef DIVINE_STRIKE_H
#define DIVINE_STRIKE_H

/*!
 * \file DivineStrike.h
 */

#include "Languages.h"
#include "Weapon.h"

class DivineStrike : public Weapon {
 public:
  DivineStrike()
      : Weapon(data::Weapon::nameDivineStrike, 1000, WeaponType::fist,
               data::Weapon::statementDivineStrike) {}

  ~DivineStrike() override = default;
};

#endif