#include "elevation/weapon/weapon_writer.h"

#include <fmt/color.h>

#include "elevation/utils/pause.h"

namespace elevation::weapon {
void print(const Weapon& weapon) {
  utils::pause();

  fmt::print(fg(fmt::color::magenta) | fmt::emphasis::bold, "\n Nom : ");
  fmt::print(fg(fmt::color::red) | fmt::emphasis::bold, weapon.name);

  fmt::print(fg(fmt::color::magenta) | fmt::emphasis::bold,
             "\n Points d'attaque : ");
  fmt::print(fg(fmt::color::red) | fmt::emphasis::bold, "{}", weapon.nb_damage);

  fmt::print(fg(fmt::color::magenta) | fmt::emphasis::bold, "\n Type : ");
  fmt::print(fg(fmt::color::red) | fmt::emphasis::bold,
             informationWeaponType(weapon));

  if (weapon.type == weapon::Type::fireArm) {
    fmt::print(fg(fmt::color::magenta) | fmt::emphasis::bold,
               "\n Nombre de munitions : ");
    fmt::print(fg(fmt::color::red) | fmt::emphasis::bold, "{}",
               weapon.durability);

    fmt::print(fg(fmt::color::magenta) | fmt::emphasis::bold,
               "\n Nombre de munitions utilisés par un tir : ");
    fmt::print(fg(fmt::color::red) | fmt::emphasis::bold, "{}",
               weapon.durability_loose_per_use);
  }
}

std::string_view informationWeaponType(const Weapon& weapon) {
  switch (weapon.type) {
    case Type::fist:
      return "poing";
    case Type::meleeWeapon:
      return "arme de mélée";
    case Type::fireArm:
      return "arme à feu";
    default:
      return "";
  }
}
}  // namespace elevation::weapon
