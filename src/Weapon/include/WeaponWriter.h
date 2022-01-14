#ifndef WEAPON_WRITER_H
#define WEAPON_WRITER_H

#include "Weapon.h"

namespace weapon {
void print(const Weapon& weapon);
std::string informationWeaponType(const Weapon& weapon);
}  // namespace weapon

#endif