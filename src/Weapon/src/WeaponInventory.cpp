/*!
 * \file WeaponInventory.cpp
 */

#include "WeaponInventory.h"

#include "WeaponFactory.h"

bool WeaponInventory::addWeapon(std::unique_ptr<const Weapon>&& weapon) {
  auto [positionWeapon, present] = weapons_.insert(std::move(weapon));
  return !present;
}

void WeaponInventory::deleteWeapon(const std::string& nameWeapon) {
  weapons_.erase(std::find_if(std::cbegin(weapons_), std::cend(weapons_),
                              [&nameWeapon](const auto& weapon) {
                                return nameWeapon == weapon->name();
                              }));
}

void WeaponInventory::deleteWeapon(std::unique_ptr<const Weapon>&& weapon) {
  deleteWeapon(weapon->name());
}

bool WeaponInventory::containWeaponType(WeaponType weaponType) const {
  return std::find_if(std::cbegin(weapons_), std::cend(weapons_),
                      [&weaponType](const auto& weapon) {
                        return weaponType == weapon->weaponType();
                      }) != std::cend(weapons_);
}

nlohmann::json WeaponInventory::writeJson() const {
  nlohmann::json result;
  std::for_each(
      std::cbegin(weapons_), std::cend(weapons_),
      [&result](const auto& weapon) { result.push_back(weapon->writeJson()); });
  return result;
}

WeaponInventory WeaponInventory::readJson(const nlohmann::json& jsonInput) {
  WeaponInventory weaponInventory;
  std::for_each(std::cbegin(jsonInput), std::cend(jsonInput),
                [&weaponInventory](const auto& weaponJson) {
                  weaponInventory.addWeapon(
                      weaponJson.count("nbAmmo")
                          ? WeaponFactory::newFireArm(weaponJson["name"],
                                                      weaponJson["nbAmmo"])
                          : WeaponFactory::newWeapon(weaponJson["name"]));
                });

  return weaponInventory;
}