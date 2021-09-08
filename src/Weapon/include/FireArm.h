#ifndef FIRE_ARM_H
#define FIRE_ARM_H

/*!
 * \file FireArm.h
 */

#include "Languages.h"
#include "Weapon.h"

// class FireArm : public Weapon {
//  protected:
//   mutable int nbAmmo_;
//   int nbAmmoForOneShot_;

//  protected:
//   FireArm(const std::string& name, const int& damageWeapon, const int&
//   nbAmmo,
//           const int& nbAmmoForOneShot, const std::string& statement)
//       : Weapon(name, damageWeapon, WeaponType::fireArm, statement),
//         nbAmmo_(nbAmmo),
//         nbAmmoForOneShot_(nbAmmoForOneShot) {}

//  public:
//   ~FireArm() override = default;

//   nlohmann::json writeJson() const override {
//     return {{"name", name()}, {"nbAmmo", nbAmmo_}};
//   }

//   void attack(Entity* const entity) const override {
//     // if the player has at least one ammo, she can attack
//     if (nbAmmo_ > 0) {
//       Weapon::attack(entity);
//       nbAmmo_ -= nbAmmoForOneShot_;
//     }
//   }

//   const int& nbAmmo() const { return nbAmmo_; }
//   const int& nbAmmoForOneShot() const { return nbAmmoForOneShot_; }
// };

static auto writeJsonFireArm = [](const std::string& name,
                                  int nbAmmo) -> nlohmann::json {
  return {{"name", name}, {"nbAmmo", nbAmmo}};
};

struct FireArm : Weapon {
  virtual int nbAmmo() const = 0;
  virtual int nbAmmoForOneShot() const = 0;
  virtual ~FireArm() = default;
};

#endif