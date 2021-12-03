/*!
 * \file WeaponWriter.cpp
 */

#include "WeaponWriter.h"

#include <cpp-terminal/terminal.h>

#include "Pause.h"

namespace weapon {
WeaponWriter::WeaponWriter(const Weapon& weapon) : weapon_(weapon) {}

void WeaponWriter::informationWeapon() const {
  Pause::pause();

  std::cout << "\n " << Term::color(Term::fg::magenta)
            << Term::color(Term::style::bold)
            << "Nom : " << Term::color(Term::fg::reset)
            << Term::color(Term::style::reset);

  std::cout << Term::color(Term::fg::red) << Term::color(Term::style::bold)
            << weapon_.name << Term::color(Term::fg::reset)
            << Term::color(Term::style::reset);

  std::cout << "\n " << Term::color(Term::fg::magenta)
            << Term::color(Term::style::bold)
            << "Points d'attaque : " << Term::color(Term::fg::reset)
            << Term::color(Term::style::reset);

  std::cout << Term::color(Term::fg::red) << Term::color(Term::style::bold)
            << weapon_.nb_damage << Term::color(Term::fg::reset)
            << Term::color(Term::style::reset);

  std::cout << "\n " << Term::color(Term::fg::magenta)
            << Term::color(Term::style::bold)
            << "Type : " << Term::color(Term::fg::reset)
            << Term::color(Term::style::reset);

  std::cout << Term::color(Term::fg::red) << Term::color(Term::style::bold)
            << informationWeaponType() << Term::color(Term::fg::reset)
            << Term::color(Term::style::reset);

  if (weapon_.type == weapon::Type::fireArm) {
    std::cout << "\n " << Term::color(Term::fg::magenta)
              << Term::color(Term::style::bold)
              << "Nombre de munitions : " << Term::color(Term::fg::reset)
              << Term::color(Term::style::reset);

    std::cout << Term::color(Term::fg::red) << Term::color(Term::style::bold)
              << weapon_.durability << Term::color(Term::fg::reset)
              << Term::color(Term::style::reset);

    std::cout << "\n " << Term::color(Term::fg::magenta)
              << Term::color(Term::style::bold)
              << "Nombre de munitions utilisés par un tir : "
              << Term::color(Term::fg::reset)
              << Term::color(Term::style::reset);

    std::cout << Term::color(Term::fg::red) << Term::color(Term::style::bold)
              << weapon_.durability_loose_per_use
              << Term::color(Term::fg::reset)
              << Term::color(Term::style::reset);
  }
}

std::string WeaponWriter::informationWeaponType() const {
  switch (weapon_.type) {
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
}  // namespace weapon