#ifndef KATANA_H
#define KATANA_H

/*!
 * \file Katana.h
 */

#include "Languages.h"
#include "Weapon.h"

struct Katana : Weapon {
  const std::string& name() const override { return data::Weapon::nameKatana; }
  int damageWeapon() const override { return 50; }
  WeaponType weaponType() const override { return WeaponType::meleeWeapon; }
  const std::string& statement() const override {
    return data::Weapon::statementUseKatana;
  }
  nlohmann::json writeJson() const override {
    return writeJsonNonFireArm(name());
  }
  void attack(Entity* const entity) const override {
    entity->decreaseLifePoints(damageWeapon());
  }
  ~Katana() = default;
};

#endif