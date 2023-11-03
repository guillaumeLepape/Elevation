#pragma once

#include "weapon.h"

namespace weapon {
void print(const Weapon& weapon);
std::string_view informationWeaponType(const Weapon& weapon);
}  // namespace weapon
