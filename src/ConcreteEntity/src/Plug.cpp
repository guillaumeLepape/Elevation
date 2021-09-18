/*!
 * \file Plug.cpp
 */

#include "Plug.h"

Plug::Plug(const std::string& name, const int& nbLifePoints,
           std::unique_ptr<const Weapon>&& weapon)
    : Entity(name, nbLifePoints, nbLifePoints), weapon_(std::move(weapon)) {}

void Plug::changeWeapon(const Weapon* newWeapon) {
  weapon_ = std::move(std::unique_ptr<const Weapon>(newWeapon));
}