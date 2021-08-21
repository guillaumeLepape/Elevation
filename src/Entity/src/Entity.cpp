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
