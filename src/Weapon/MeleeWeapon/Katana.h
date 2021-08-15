#ifndef KATANA_H
#define KATANA_H

/*!
 * \file Katana.h
 */

#include "Languages.h"
#include "Weapon.h"

class Katana : public Weapon {
 public:
  Katana()
      : Weapon(data::Weapon::nameKatana, 50, WeaponType::meleeWeapon,
               data::Weapon::statementUseKatana) {}

  ~Katana() override = default;
};

#endif