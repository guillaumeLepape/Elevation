#ifndef PLUG_H
#define PLUG_H

#include "HealthBar.h"
#include "Weapon.h"

namespace entity {
class Plug {
 private:
  std::string name_;
  weapon::Weapon weapon_;

 public:
  HealthBar healthBar_;

 public:
  Plug(const std::string& name, const int& nbLifePoints = 100,
       weapon::Weapon&& weapon = weapon::NoWeapon());

  Plug(const Plug&) = delete;
  Plug(Plug&&) = default;

  Plug& operator=(const Plug&) = delete;
  Plug& operator=(Plug&&) = default;

  ~Plug() = default;

  const std::string& name() const { return name_; }
  void changeWeapon(weapon::Weapon&& newWeapon);

  weapon::Weapon& weapon() { return weapon_; }

  const HealthBar& healthBar() const { return healthBar_; }
  HealthBar& healthBar() { return healthBar_; }
};
}  // namespace entity

#endif