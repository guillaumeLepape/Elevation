#ifndef HEROINE_H
#define HEROINE_H

/*!
 * \file Heroine.h
 */

#include "Languages.h"
#include "Weapon.h"

class Heroine : public Weapon {
 public:
  Heroine()
      : Weapon(data::Weapon::nameHeroine, 50, WeaponType::meleeWeapon, "") {}

  ~Heroine() override = default;
};

#endif