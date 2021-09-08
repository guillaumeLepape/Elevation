#ifndef NINE_MM_H
#define NINE_MM_H

/*!
 * \file Ninemm.h
 */

#include "FireArm.h"
#include "Languages.h"

// class Ninemm : public FireArm {
//  public:
//   Ninemm(const int& nbAmmo)
//       : FireArm(data::Weapon::nameNinemm, 70, nbAmmo, 1,
//                 data::Weapon::statementUseNinemm) {}

//   ~Ninemm() override = default;
// };

struct Ninemm : FireArm {
  Ninemm(int nbAmmo) : nbAmmo_(nbAmmo) {}

  const std::string& name() const override { return data::Weapon::nameNinemm; }
  int damageWeapon() const override { return 70; }
  WeaponType weaponType() const override { return WeaponType::fireArm; }
  const std::string& statement() const override {
    return data::Weapon::statementUseNinemm;
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
  int nbAmmoForOneShot() const override { return 1; }

  virtual ~Ninemm() = default;

 private:
  mutable int nbAmmo_;
};

#endif