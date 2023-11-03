#pragma once

#include "elevation/weapon/weapon.h"

namespace elevation::weapon {
void print(const Weapon& weapon);
std::string_view informationWeaponType(const Weapon& weapon);
}  // namespace elevation::weapon
