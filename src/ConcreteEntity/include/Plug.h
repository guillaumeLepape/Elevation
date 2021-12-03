#ifndef PLUG_H
#define PLUG_H

/*!
 * \file Plug.h
 */

#include <memory>

#include "Entity.h"

class Plug : public Entity {
 private:
  weapon::Weapon weapon_;

 public:
  Plug(const std::string& name, const int& nbLifePoints = 100,
       weapon::Weapon&& weapon = weapon::NoWeapon());

  Plug(const Plug&) = delete;
  Plug(Plug&&) = default;

  Plug& operator=(const Plug&) = delete;
  Plug& operator=(Plug&&) = default;

  virtual ~Plug() = default;

  void changeWeapon(weapon::Weapon&& newWeapon);

  weapon::Weapon& weapon() { return weapon_; }
};

#endif