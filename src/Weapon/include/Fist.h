#ifndef FIST_H
#define FIST_H

/*!
 * \file Fist.h
 */

#include "Languages.h"
#include "Weapon.h"

// class Fist : public Weapon {
//  public:
//   Fist()
//       : Weapon(data::Weapon::nameFist, 20, WeaponType::fist,
//                data::Weapon::statementUseFist) {}

//   Fist(const Fist& fist) = delete;

//   ~Fist() override = default;
// };

struct Fist : Weapon {
  const std::string& name() const override { return data::Weapon::nameFist; }
  int damageWeapon() const override { return 20; }
  WeaponType weaponType() const override { return WeaponType::fist; }
  const std::string& statement() const override {
    return data::Weapon::statementUseFist;
  }
  nlohmann::json writeJson() const override {
    return writeJsonNonFireArm(name());
  }
  void attack(Entity* const entity) const override {
    entity->decreaseLifePoints(damageWeapon());
  }
  ~Fist() = default;
};

#endif