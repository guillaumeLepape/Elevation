#ifndef CHOPPER_H
#define CHOPPER_H

/*!
 * \file Chopper.h
 */

struct Chopper : Weapon {
  const std::string& name() const override { return data::Weapon::nameChopper; }
  int damageWeapon() const override { return 80; }
  WeaponType weaponType() const override { return WeaponType::meleeWeapon; }
  const std::string& statement() const override {
    return data::Weapon::statementUseChopper;
  }
  nlohmann::json writeJson() const override {
    return writeJsonNonFireArm(name());
  }
  void attack(Entity* const entity) const override {
    entity->decreaseLifePoints(damageWeapon());
  }
  ~Chopper() = default;
};

#endif