#ifndef FIST_H
#define FIST_H

/*!
 * \file Fist.h
 */

#include "Languages.h"
#include "Weapon.h"

class Fist : public Weapon {
 public:
  Fist()
      : Weapon(data::Weapon::nameFist, 20, WeaponType::fist,
               data::Weapon::statementUseFist) {}

  Fist(const Fist& fist) = delete;

  ~Fist() override = default;
};

#endif