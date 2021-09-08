#ifndef DIVINE_STRIKE_H
#define DIVINE_STRIKE_H

/*!
 * \file DivineStrike.h
 */

#include "Languages.h"
#include "Weapon.h"

// class DivineStrike : public Weapon {
//  public:
//   DivineStrike()
//       : Weapon(data::Weapon::nameDivineStrike, 1000, WeaponType::fist,
//                data::Weapon::statementDivineStrike) {}

//   ~DivineStrike() override = default;
// };

struct DivineStrike : Weapon {
  const std::string& name() const override {
    return data::Weapon::nameDivineStrike;
  }
  int damageWeapon() const override { return 1000; }
  WeaponType weaponType() const override { return WeaponType::fist; }
  const std::string& statement() const override {
    return data::Weapon::statementDivineStrike;
  }
  nlohmann::json writeJson() const override {
    return writeJsonNonFireArm(name());
  }
  void attack(Entity* const entity) const override {
    entity->decreaseLifePoints(damageWeapon());
  }
  ~DivineStrike() = default;
};

#endif