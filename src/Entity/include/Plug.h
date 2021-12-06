#ifndef PLUG_H
#define PLUG_H

/*!
 * \file Plug.h
 */

#include "HealthBar.h"
#include "Weapon.h"

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

  virtual ~Plug() = default;

  const std::string& name() const { return name_; }
  void changeWeapon(weapon::Weapon&& newWeapon);

  weapon::Weapon& weapon() { return weapon_; }

  const HealthBar& healthBar() const { return healthBar_; }
  HealthBar& healthBar() { return healthBar_; }
};

#endif