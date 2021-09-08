#ifndef AK_47_H
#define AK_47_H

/*!
 * \file AK47.h
 */

#include "FireArm.h"
#include "Languages.h"

struct AK47 : FireArm {
  AK47(int nbAmmo) : nbAmmo_(nbAmmo) {}

  const std::string& name() const override { return data::Weapon::nameAK47; }
  int damageWeapon() const override { return 150; }
  WeaponType weaponType() const override { return WeaponType::fireArm; }
  const std::string& statement() const override {
    return data::Weapon::statementUseAK47;
  }
  nlohmann::json writeJson() const override {
    return writeJsonFireArm(name(), nbAmmo());
  }
  void attack(Entity* const entity) const override {
    if (nbAmmo_ > 0) {
      entity->decreaseLifePoints(damageWeapon());
      nbAmmo_ -= nbAmmoForOneShot();
    }
  }
  int nbAmmo() const override { return nbAmmo_; }
  int nbAmmoForOneShot() const override { return 10; }

  virtual ~AK47() = default;

 private:
  mutable int nbAmmo_;
};

#endif