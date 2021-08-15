#ifndef WEAPON_WRITER_H
#define WEAPON_WRITER_H

/*!
 * \file WeaponWriter.h
 */

#include "Weapon.h"

class WeaponWriter {
 private:
  const Weapon* const weapon_;

  std::string informationWeaponType() const;

 public:
  WeaponWriter(const Weapon* weapon);

  virtual void informationWeapon() const;
};

#endif