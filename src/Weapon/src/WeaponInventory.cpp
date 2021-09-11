/*!
 * \file WeaponInventory.cpp
 */

#include "WeaponInventory.h"

#include "WeaponFactory.h"

bool WeaponInventory::addWeapon(std::unique_ptr<const Weapon>&& weapon) {
  auto [positionWeapon, present] =
      WeaponInventoryBase::insert(std::move(weapon));
  return !present;
}

void WeaponInventory::deleteWeapon(const std::string& nameWeapon) {
  WeaponInventoryBase::erase(std::find_if(WeaponInventoryBase::cbegin(),
                                          WeaponInventoryBase::cend(),
                                          [&nameWeapon](const auto& weapon) {
                                            return nameWeapon == weapon->name();
                                          }));
}

void WeaponInventory::deleteWeapon(std::unique_ptr<const Weapon>&& weapon) {
  deleteWeapon(weapon->name());
}

bool WeaponInventory::containWeaponType(WeaponType weaponType) const {
  return std::find_if(WeaponInventoryBase::cbegin(),
                      WeaponInventoryBase::cend(),
                      [&weaponType](const auto& weapon) {
                        return weaponType == weapon->weaponType();
                      }) != WeaponInventoryBase::cend();
}

nlohmann::json WeaponInventory::writeJson() const {
  nlohmann::json result;
  std::for_each(
      WeaponInventoryBase::cbegin(), WeaponInventoryBase::cend(),
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