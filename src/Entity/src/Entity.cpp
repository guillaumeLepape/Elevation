/*!
 * \file Entity.cpp
 */

#include "Entity.h"

Entity::Entity(const std::string& name, const int& nbLifePoints,
               const int& maxNbLifePoints)
    : name_(name),
      nbLifePoints_(nbLifePoints),
      maxNbLifePoints_(maxNbLifePoints) {}

std::string Entity::healthBar() const {
  return std::to_string(nbLifePoints_) + "/" +
         std::to_string(maxNbLifePoints_) + " points de vie.";
}

void attack(Entity* const entity, const weapon::Weapon& weapon) {
  if (weapon.durability > 0) {
    entity->decreaseLifePoints(weapon.nb_damage);
    weapon.durability -= weapon.durability_loose_per_use;
  }
}