#ifndef WEAPON_INVENTORY_H
#define WEAPON_INVENTORY_H

/*!
 * \file WeaponInventory.h
 */

#include <set>
#include <type_traits>

#include "Fist.h"
#include "NoWeapon.h"
#include "Weapon.h"
#include "WeaponFactory.h"

static auto comparatorWeapon = [](const auto& weapon1, const auto& weapon2) {
  return weapon1->weaponType() == weapon2->weaponType()
             ? weapon1->damageWeapon() < weapon2->damageWeapon()
             : weapon1->weaponType() < weapon2->weaponType();
};

using WeaponInventoryBase =
    std::set<std::unique_ptr<const Weapon>, decltype(comparatorWeapon)>;

struct WeaponInventory : public WeaponInventoryBase {
  WeaponInventory() : WeaponInventoryBase{comparatorWeapon} {}

  WeaponInventory(const nlohmann::json& jsonInput)
      : WeaponInventory{[&jsonInput]() {
          WeaponInventory weaponInventory;
          std::for_each(
              std::cbegin(jsonInput), std::cend(jsonInput),
              [&weaponInventory](const auto& weaponJson) {
                weaponInventory.addWeapon(
                    weaponJson.count("nbAmmo")
                        ? WeaponFactory::newFireArm(weaponJson["name"],
                                                    weaponJson["nbAmmo"])
                        : WeaponFactory::newWeapon(weaponJson["name"]));
              });

          return weaponInventory;
        }()} {}

  WeaponInventory(std::unique_ptr<const Weapon>&& weapon)
      : WeaponInventoryBase{[&weapon]() {
          auto result = WeaponInventoryBase{comparatorWeapon};
          result.insert(std::move(weapon));
          return result;
        }()} {}

  WeaponInventory(const WeaponInventory&) = delete;
  WeaponInventory(WeaponInventory&&) = default;

  WeaponInventory& operator=(const WeaponInventory&) = delete;
  WeaponInventory& operator=(WeaponInventory&&) = default;

  ~WeaponInventory() = default;

  bool addWeapon(std::unique_ptr<const Weapon>&&);
  void deleteWeapon(const std::string& nameWeapon);
  void deleteWeapon(std::unique_ptr<const Weapon>&& weapon);
  bool containWeaponType(WeaponType weaponType) const;

  const Weapon* find(const std::string& name);

  nlohmann::json writeJson() const;
};

#endif