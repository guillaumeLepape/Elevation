#pragma once

#include "elevation/entity/health_bar.h"
#include "elevation/weapon/weapon.h"

namespace entity {
class Plug {
 private:
  std::string name_;
  weapon::Weapon weapon_;

 public:
  HealthBar healthBar_;

 public:
  Plug(const std::string& name, int nbLifePoints = 100,
       weapon::Weapon&& weapon = weapon::NoWeapon());

  Plug(const Plug&) = delete;

  Plug& operator=(const Plug&) = delete;

  const std::string& name() const { return name_; }
  void changeWeapon(weapon::Weapon&& newWeapon);

  const weapon::Weapon& weapon() const { return weapon_; }
  weapon::Weapon& weapon() { return weapon_; }

  const HealthBar& healthBar() const { return healthBar_; }
  HealthBar& healthBar() { return healthBar_; }
};
}  // namespace entity
