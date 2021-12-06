/*!
 * \file Plug.cpp
 */

#include "Plug.h"

Plug::Plug(const std::string& name, const int& nbLifePoints,
           weapon::Weapon&& weapon)
    : name_{name},
      weapon_{std::move(weapon)},
      healthBar_{nbLifePoints, nbLifePoints} {}

void Plug::changeWeapon(weapon::Weapon&& newWeapon) {
  weapon_ = std::move(newWeapon);
}