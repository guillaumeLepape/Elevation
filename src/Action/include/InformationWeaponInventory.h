#ifndef INFORMATION_WEAPON_INVENTORY_H
#define INFORMATION_WEAPON_INVENTORY_H

#include <cpp-terminal/terminal.h>

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
    std::cout << "\n " << Term::color(Term::bg::magenta)
              << Term::color(Term::style::bold)
              << "Informations à propos des armes que vous possèdez"
              << Term::color(Term::bg::reset)
              << Term::color(Term::style::reset);

    utils::writeSeparators();

    std::for_each(std::cbegin(weaponInventory_), std::cend(weaponInventory_),
                  [](const auto& weapon) { weapon::print(weapon); });
  }
};
}  // namespace action

#endif