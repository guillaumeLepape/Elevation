#ifndef WEAPON_FACTORY_H
#define WEAPON_FACTORY_H

/*!
 * \file WeaponFactory.h
 */

#include "AK47.h"
#include "Chopper.h"
#include "Cutter.h"
#include "Fist.h"
#include "Hammer.h"
#include "Katana.h"
#include "Knife.h"
#include "Ninemm.h"
#include "WeaponFistCombo.h"

class WeaponFactory {
 public:
  static std::unique_ptr<Weapon> newWeapon(const std::string& nameWeapon) {
    if (nameWeapon == data::Weapon::nameFist) {
      return std::unique_ptr<Weapon>(new Fist());
    }
    if (nameWeapon == data::Weapon::nameKnife) {
      return std::unique_ptr<Weapon>(new Knife());
    }
    if (nameWeapon == data::Weapon::nameKatana) {
      return std::unique_ptr<Weapon>(new Katana());
    }
    if (nameWeapon == data::Weapon::nameCutter) {
      return std::unique_ptr<Weapon>(new Cutter());
    }
    if (nameWeapon == data::Weapon::nameHammer) {
      return std::unique_ptr<Weapon>(new Hammer());
    }
    if (nameWeapon == data::Weapon::nameChopper) {
      return std::unique_ptr<Weapon>(new Chopper());
    }
    assert(false);
  }

  static std::unique_ptr<Weapon> newFireArm(const std::string& nameWeapon,
                                            const int& nbAmmo) {
    if (nameWeapon == data::Weapon::nameNinemm) {
      return std::unique_ptr<Weapon>(new Ninemm(nbAmmo));
    }
    if (nameWeapon == data::Weapon::nameAK47) {
      return std::unique_ptr<Weapon>(new AK47(nbAmmo));
    }
    assert(false);
  }
};

#endif