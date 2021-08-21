#ifndef HAMMER_H
#define HAMMER_H

/*!
 * \file Hammer.h
 */

#include "Languages.h"
#include "Weapon.h"

class Hammer : public Weapon {
 public:
  Hammer()
      : Weapon(data::Weapon::nameHammer, 40, WeaponType::meleeWeapon,
               data::Weapon::statementUseHammer) {}

  ~Hammer() override = default;
};

#endif