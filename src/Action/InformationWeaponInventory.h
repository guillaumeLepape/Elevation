#ifndef INFORMATION_WEAPON_INVENTORY_H
#define INFORMATION_WEAPON_INVENTORY_H

/*!
 * \file InformationWeaponInventory.h
 */

#include <cpp-terminal/terminal.h>

#include "Action.h"
#include "WeaponWriter.h"

class InformationWeaponInventory : public Action {
 private:
  const WeaponInventory* const weaponInventory_;

 public:
  InformationWeaponInventory(const WeaponInventory* const weaponInventory,
                             const std::string& statement,
                             const std::string& result)
      : Action(statement, result), weaponInventory_(weaponInventory) {}

  void triggerAction() override {
    std::cout << "\n " << Term::color(Term::bg::magenta)
              << Term::color(Term::style::bold)
              << "Informations à propos des armes que vous possèdez"
              << Term::color(Term::bg::reset)
              << Term::color(Term::style::reset);

    std::cout << "\n"
              << Term::color(Term::fg::black) << Term::color(Term::style::bold)
              << "========" << Term::color(Term::fg::reset)
              << Term::color(Term::style::reset);

    for (auto w = weaponInventory_->cbegin(); w != weaponInventory_->end();
         w++) {
      WeaponWriter weaponWriter((*w).get());
      weaponWriter.informationWeapon();
    }
  }
};

#endif