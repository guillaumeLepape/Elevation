#ifndef WEAPON_H
#define WEAPON_H

/*!
 * \file Weapon.h
 */

#include <nlohmann/json.hpp>

#include "Entity.h"

enum class WeaponType { noWeapon = -1, fist = 0, meleeWeapon = 1, fireArm = 2 };

static auto writeJsonNonFireArm =
    [](const std::string& name) -> nlohmann::json {
  return {{"name", name}};
};

struct Weapon {
  virtual const std::string& name() const = 0;
  virtual int damageWeapon() const = 0;
  virtual WeaponType weaponType() const = 0;
  virtual const std::string& statement() const = 0;
  virtual nlohmann::json writeJson() const = 0;
  virtual void attack(Entity* const entity) const = 0;
  virtual ~Weapon() = default;
};

#endif