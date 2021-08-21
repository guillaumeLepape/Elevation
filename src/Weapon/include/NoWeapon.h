#ifndef NO_WEAPON_H
#define NO_WEAPON_H

/*!
 * \file NoWeapon.h
 */

#include "Languages.h"
#include "Weapon.h"

class NoWeapon : public Weapon {
 public:
  NoWeapon()
      : Weapon(data::Weapon::nameNoWeapon, 0, WeaponType::noWeapon,
               data::Weapon::statementUseNoWeapon) {}

  ~NoWeapon() override = default;
};

#endif