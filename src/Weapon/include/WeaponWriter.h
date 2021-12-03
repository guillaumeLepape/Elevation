#ifndef WEAPON_WRITER_H
#define WEAPON_WRITER_H

/*!
 * \file WeaponWriter.h
 */

#include "Weapon.h"

namespace weapon {
class WeaponWriter {
 private:
  const Weapon& weapon_;

  std::string informationWeaponType() const;

 public:
  WeaponWriter(const Weapon& weapon);

  void informationWeapon() const;
};
}  // namespace weapon

#endif