#ifndef INFORMATION_WEAPON_INVENTORY_H
#define INFORMATION_WEAPON_INVENTORY_H

#include <fmt/color.h>

#include <range/v3/algorithm/for_each.hpp>

#include "NameType.h"
#include "UtilsWriter.h"
#include "WeaponWriter.h"

namespace action {
class InformationWeaponInventory {
 private:
  Statement statement_;

  const weapon::WeaponInventory& weaponInventory_;

 public:
  InformationWeaponInventory(const weapon::WeaponInventory& weaponInventory,
                             const Statement& statement)
      : statement_{statement}, weaponInventory_{weaponInventory} {}

  const std::string& statement() const { return statement_.get(); }

  void trigger() {
    fmt::print("\n ");
    fmt::print(bg(fmt::color::magenta) | fmt::emphasis::bold,
               "Informations à propos des armes que vous possèdez");

    utils::writeSeparators();

    ranges::for_each(weaponInventory_, weapon::print);
  }
};
}  // namespace action

#endif