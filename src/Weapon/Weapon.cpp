/*!
 * \file Weapon.cpp
 */

#include "Weapon.h"

Weapon::Weapon(const std::string& name, const int& damageWeapon,
               WeaponType weaponType, const std::string& statement)
    : name_(name),
      damageWeapon_(damageWeapon),
      weaponType_(weaponType),
      statement_(statement) {}

nlohmann::json Weapon::writeJson() const { return {{"name", name_}}; }

void Weapon::attack(Entity* entity) const {
  entity->decreaseLifePoints(damageWeapon_);
}

bool operator==(const Weapon& weapon1, const Weapon& weapon2) {
  return ((weapon1.name_ == weapon2.name_) &&
          (weapon1.damageWeapon_ == weapon2.damageWeapon_) &&
          (weapon1.weaponType_ == weapon2.weaponType_));
}
