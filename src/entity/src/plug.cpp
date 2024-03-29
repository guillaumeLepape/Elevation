#include "elevation/entity/plug.h"

namespace elevation::entity {
Plug::Plug(const std::string& name, int nbLifePoints, weapon::Weapon&& weapon)
    : name_{name},
      weapon_{std::move(weapon)},
      healthBar_{nbLifePoints, nbLifePoints} {}

void Plug::changeWeapon(weapon::Weapon&& newWeapon) {
  weapon_ = std::move(newWeapon);
}
}  // namespace elevation::entity
