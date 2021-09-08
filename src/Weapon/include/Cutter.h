#ifndef CUTTER_H
#define CUTTER_H

/*!
 * \file Cutter.h
 */

#include "Languages.h"
#include "Weapon.h"

struct Cutter : Weapon {
  const std::string& name() const override { return data::Weapon::nameCutter; }
  int damageWeapon() const override { return 15; }
  WeaponType weaponType() const override { return WeaponType::meleeWeapon; }
  const std::string& statement() const override {
    return data::Weapon::statementUseCutter;
  }
  nlohmann::json writeJson() const override {
    return writeJsonNonFireArm(name());
  }
  void attack(Entity* const entity) const override {
    entity->decreaseLifePoints(damageWeapon());
  }
  ~Cutter() = default;
};

#endif