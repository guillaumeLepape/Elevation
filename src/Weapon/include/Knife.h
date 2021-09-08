#ifndef KNIFE_H
#define KNIFE_H

/*!
 * \file Knife.h
 */

#include "Languages.h"
#include "Weapon.h"

struct Knife : Weapon {
  const std::string& name() const override { return data::Weapon::nameKnife; }
  int damageWeapon() const override { return 30; }
  WeaponType weaponType() const override { return WeaponType::meleeWeapon; }
  const std::string& statement() const override {
    return data::Weapon::statementUseKnife;
  }
  nlohmann::json writeJson() const override {
    return writeJsonNonFireArm(name());
  }
  void attack(Entity* const entity) const override {
    entity->decreaseLifePoints(damageWeapon());
  }
  ~Knife() = default;
};

#endif