#ifndef INFORMATION_WEAPON_INVENTORY_H
#define INFORMATION_WEAPON_INVENTORY_H

/*!
 * \file InformationWeaponInventory.h
 */

#include <cpp-terminal/terminal.h>

#include "NameType.h"
#include "UtilsWriter.h"
#include "WeaponWriter.h"

class InformationWeaponInventory {
 private:
  Statement statement_;

  const WeaponInventory& weaponInventory_;

 public:
  InformationWeaponInventory(const WeaponInventory& weaponInventory,
                             const Statement& statement)
      : statement_(statement), weaponInventory_(weaponInventory) {}

  const std::string& statement() const { return statement_.get(); }

  void triggerAction() {
    std::cout << "\n " << Term::color(Term::bg::magenta)
              << Term::color(Term::style::bold)
              << "Informations à propos des armes que vous possèdez"
              << Term::color(Term::bg::reset)
              << Term::color(Term::style::reset);

    utils::writeSeparators();

    std::for_each(std::cbegin(weaponInventory_), std::cend(weaponInventory_),
                  [](const auto& weapon) {
                    WeaponWriter weaponWriter(weapon.get());
                    weaponWriter.informationWeapon();
                  });
  }
};

#endif