/*!
 * \file Plug.cpp
 */

#include "Plug.h"

Plug::Plug(const std::string& name, const int& nbLifePoints,
           weapon::Weapon&& weapon)
    : Entity(name, nbLifePoints, nbLifePoints), weapon_(std::move(weapon)) {}

void Plug::changeWeapon(weapon::Weapon&& newWeapon) {
  weapon_ = std::move(newWeapon);
}