/*!
 * \file WeaponInventory.cpp
 */

#include "WeaponInventory.h"

bool WeaponInventory::addWeapon(std::unique_ptr<const Weapon>&& weapon) {
  bool present = true;
  std::tie(std::ignore, present) =
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

const Weapon* WeaponInventory::find(const std::string& name) {
  auto weaponPtr = std::find_if(
      WeaponInventoryBase::cbegin(), WeaponInventoryBase::cend(),
      [&name](const auto& weapon) { return weapon->name() == name; });

  if (weaponPtr == WeaponInventoryBase::cend()) {
    return new const NoWeapon();
  } else {
    return weaponPtr->get();
  }
}

nlohmann::json WeaponInventory::writeJson() const {
  nlohmann::json result;
  std::for_each(
      WeaponInventoryBase::cbegin(), WeaponInventoryBase::cend(),
      [&result](const auto& weapon) { result.push_back(weapon->writeJson()); });
  return result;
}