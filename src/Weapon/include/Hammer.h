#ifndef HAMMER_H
#define HAMMER_H

/*!
 * \file Hammer.h
 */

#include "Languages.h"
#include "Weapon.h"

struct Hammer : Weapon {
  const std::string& name() const override { return data::Weapon::nameHammer; }
  int damageWeapon() const override { return 40; }
  WeaponType weaponType() const override { return WeaponType::meleeWeapon; }
  const std::string& statement() const override {
    return data::Weapon::statementUseHammer;
  }
  nlohmann::json writeJson() const override {
    return writeJsonNonFireArm(name());
  }
  void attack(Entity* const entity) const override {
    entity->decreaseLifePoints(damageWeapon());
  }
  ~Hammer() = default;
};

#endif