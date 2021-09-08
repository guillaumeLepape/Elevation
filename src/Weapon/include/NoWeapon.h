#ifndef NO_WEAPON_H
#define NO_WEAPON_H

/*!
 * \file NoWeapon.h
 */

#include "Languages.h"
#include "Weapon.h"

struct NoWeapon : Weapon {
  const std::string& name() const override {
    return data::Weapon::nameNoWeapon;
  }
  int damageWeapon() const override { return 0; }
  WeaponType weaponType() const override { return WeaponType::noWeapon; }
  const std::string& statement() const override {
    return data::Weapon::statementUseNoWeapon;
  }
  nlohmann::json writeJson() const override {
    return writeJsonNonFireArm(name());
  }
  void attack(Entity* const entity) const override {
    entity->decreaseLifePoints(damageWeapon());
  }
  ~NoWeapon() = default;
};

#endif