#ifndef KNIFE_H
#define KNIFE_H

/*!
 * \file Knife.h
 */

#include "Languages.h"
#include "Weapon.h"

class Knife : public Weapon {
 public:
  Knife()
      : Weapon(data::Weapon::nameKnife, 30, WeaponType::meleeWeapon,
               data::Weapon::statementUseKnife) {}

  ~Knife() override = default;
};

#endif