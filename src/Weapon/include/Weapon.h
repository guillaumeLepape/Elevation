#ifndef WEAPON_H
#define WEAPON_H

/*!
 * \file Weapon.h
 */

#include <optional>
#include <set>
#include <variant>

#include <nlohmann/json.hpp>

#include "Languages.h"

namespace weapon {
enum class Type { noWeapon = -1, fist = 0, meleeWeapon = 1, fireArm = 2 };

struct Weapon {
  std::string name;
  int nb_damage;
  Type type;
  std::string statement;
  mutable int durability;
  int durability_loose_per_use;

  friend bool operator<(const Weapon& weapon1, const Weapon& weapon2) {
    return weapon1.type == weapon2.type ? weapon1.nb_damage < weapon2.nb_damage
                                        : weapon1.type < weapon2.type;
  }
};

Weapon NoWeapon();
Weapon Fist();
Weapon DivineStrike();
Weapon Chopper();
Weapon Cutter();
Weapon Hammer();
Weapon Heroine();
Weapon Katana();
Weapon Knife();
Weapon Ninemm(int nb_ammo);
Weapon AK47(int nb_ammo);
Weapon WeaponFistCombo(const Weapon& weapon);

nlohmann::json write(const Weapon& weapon);
Weapon make_weapon(const nlohmann::json& input);

using WeaponInventory = std::set<Weapon>;

nlohmann::json write(const WeaponInventory& inventory);
WeaponInventory make_weapon_inventory(const nlohmann::json& input);

bool add(WeaponInventory& weaponInventory, Weapon&& weapon);

bool contains(const WeaponInventory& weaponInventory, Type&& type);

void remove(WeaponInventory& weaponInventory, const std::string& name);

}  // namespace weapon

#endif