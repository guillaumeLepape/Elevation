#ifndef INFORMATION_WEAPON_INVENTORY_H
#define INFORMATION_WEAPON_INVENTORY_H

/*!
 * \file InformationWeaponInventory.h
 */

#include <cpp-terminal/terminal.h>

#include "NameType.h"
#include "WeaponWriter.h"

class InformationWeaponInventory {
 private:
  const Statement& statement_;

  const WeaponInventory* const weaponInventory_;

 public:
  InformationWeaponInventory(const WeaponInventory* const weaponInventory,
                             const Statement& statement)
      : statement_(statement), weaponInventory_(weaponInventory) {}

  const std::string& statement() const { return statement_.get(); }

  void triggerAction() {
    std::cout << "\n " << Term::color(Term::bg::magenta)
              << Term::color(Term::style::bold)
              << "Informations à propos des armes que vous possèdez"
              << Term::color(Term::bg::reset)
              << Term::color(Term::style::reset);

    std::cout << "\n"
              << Term::color(Term::fg::black) << Term::color(Term::style::bold)
              << "========" << Term::color(Term::fg::reset)
              << Term::color(Term::style::reset);

    for (auto w = weaponInventory_->cbegin(); w != weaponInventory_->cend();
         w++) {
      WeaponWriter weaponWriter((*w).get());
      weaponWriter.informationWeapon();
    }
  }
};

#endif