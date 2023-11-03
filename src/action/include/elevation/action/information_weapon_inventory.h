#pragma once

#include <fmt/color.h>

#include <range/v3/algorithm/for_each.hpp>

#include "elevation/utils/concept.h"
#include "elevation/weapon/weapon_writer.h"
#include "elevation/writer/utils_writer.h"

namespace action {
template <utils::Printable T>
class InformationWeaponInventory {
 private:
  T statement_;

  const weapon::WeaponInventory& weaponInventory_;

 public:
  InformationWeaponInventory(const weapon::WeaponInventory& weaponInventory,
                             const T& statement)
      : statement_{statement}, weaponInventory_{weaponInventory} {}

  const T& statement() const { return statement_; }

  void trigger() {
    fmt::print("\n ");
    fmt::print(bg(fmt::color::magenta) | fmt::emphasis::bold,
               "Informations à propos des armes que vous possèdez");

    utils::writeSeparators();

    ranges::for_each(weaponInventory_, weapon::print);
  }
};
}  // namespace action
