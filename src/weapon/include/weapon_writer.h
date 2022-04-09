#ifndef WEAPON_WRITER_H
#define WEAPON_WRITER_H

#include "weapon.h"

namespace weapon {
void print(const Weapon& weapon);
std::string_view informationWeaponType(const Weapon& weapon);
}  // namespace weapon

#endif