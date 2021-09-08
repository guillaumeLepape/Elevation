#ifndef WEAPON_INVENTORY_H
#define WEAPON_INVENTORY_H

/*!
 * \file WeaponInventory.h
 */

#include <set>
#include <type_traits>

#include "Weapon.h"
#include "WeaponFactory.h"

static auto comparatorWeapon = [](const auto& weapon1, const auto& weapon2) {
  return weapon1->weaponType() == weapon2->weaponType()
             ? weapon1->damageWeapon() < weapon2->damageWeapon()
             : weapon1->weaponType() < weapon2->weaponType();
};

class WeaponInventory {
 public:
  std::set<std::unique_ptr<const Weapon>, decltype(comparatorWeapon)> weapons_;

 public:
  WeaponInventory() : weapons_{comparatorWeapon} {};

  WeaponInventory(std::unique_ptr<const Weapon>&& weapon)
      : weapons_{comparatorWeapon} {
    weapons_.insert(std::move(weapon));
  }
  WeaponInventory(const WeaponInventory&) = delete;
  WeaponInventory(WeaponInventory&&) = default;

  WeaponInventory& operator=(const WeaponInventory&) = delete;
  WeaponInventory& operator=(WeaponInventory&&) = default;

  ~WeaponInventory() = default;

  bool addWeapon(std::unique_ptr<const Weapon>&&);
  void deleteWeapon(const std::string& nameWeapon);
  void deleteWeapon(std::unique_ptr<const Weapon>&& weapon);
  bool containWeaponType(WeaponType weaponType) const;

  nlohmann::json writeJson() const;
  static WeaponInventory readJson(const nlohmann::json& jsonInput);

  decltype(weapons_)::const_iterator cbegin() const noexcept {
    return weapons_.cbegin();
  }
  decltype(weapons_)::const_iterator cend() const noexcept {
    return weapons_.cend();
  }
};

#endif