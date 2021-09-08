#ifndef HEROINE_H
#define HEROINE_H

/*!
 * \file Heroine.h
 */

#include "Languages.h"
#include "Weapon.h"

struct Heroine : Weapon {
  const std::string& name() const override { return data::Weapon::nameHeroine; }
  int damageWeapon() const override { return 50; }
  WeaponType weaponType() const override { return WeaponType::meleeWeapon; }
  const std::string& statement() const override { return statement_; }
  nlohmann::json writeJson() const override {
    return writeJsonNonFireArm(name());
  }
  void attack(Entity* const entity) const override {
    entity->decreaseLifePoints(damageWeapon());
  }
  ~Heroine() = default;

 private:
  std::string statement_ = "";
};

#endif