/*!
    * \file WeaponWriter.cpp
*/

#include "WeaponWriter.h"

#include <cpp-terminal/terminal.h>

#include "Pause.h"
#include "FireArm.h"

WeaponWriter::WeaponWriter( const Weapon* weapon ) :
    weapon_( weapon )
{

}

void WeaponWriter::informationWeapon() const
{
    Pause::pause();

    std::cout << "\n "
        << Term::color( Term::fg::magenta )
        << Term::color( Term::style::bold )
        << "Nom : "
        << Term::color( Term::fg::reset )
        << Term::color( Term::style::reset );

    std::cout << Term::color( Term::fg::red )
        << Term::color( Term::style::bold )
        << weapon_->name()
        << Term::color( Term::fg::reset )
        << Term::color( Term::style::reset );

    std::cout << "\n "
        << Term::color( Term::fg::magenta )
        << Term::color( Term::style::bold )
        << "Points d'attaque : "
        << Term::color( Term::fg::reset )
        << Term::color( Term::style::reset );

    std::cout << Term::color( Term::fg::red )
        << Term::color( Term::style::bold )
        << weapon_->damageWeapon()
        << Term::color( Term::fg::reset )
        << Term::color( Term::style::reset );

    std::cout << "\n "
        << Term::color( Term::fg::magenta )
        << Term::color( Term::style::bold )
        << "Type : "
        << Term::color( Term::fg::reset )
        << Term::color( Term::style::reset );

    std::cout << Term::color( Term::fg::red )
        << Term::color( Term::style::bold )
        << informationWeaponType()
        << Term::color( Term::fg::reset )
        << Term::color( Term::style::reset );

    if ( weapon_->weaponType() == WeaponType::fireArm )
    {
        std::cout << "\n "
            << Term::color( Term::fg::magenta )
            << Term::color( Term::style::bold )
            << "Nombre de munitions : "
            << Term::color( Term::fg::reset )
            << Term::color( Term::style::reset );

        std::cout << Term::color( Term::fg::red )
            << Term::color( Term::style::bold )
            << ( (FireArm*) weapon_ )->nbAmmo()
            << Term::color( Term::fg::reset )
            << Term::color( Term::style::reset );

        std::cout << "\n "
            << Term::color( Term::fg::magenta )
            << Term::color( Term::style::bold )
            << "Nombre de munitions utilisés par un tir : "
            << Term::color( Term::fg::reset )
            << Term::color( Term::style::reset );

        std::cout << Term::color( Term::fg::red )
            << Term::color( Term::style::bold )
            << ( (FireArm*) weapon_ )->nbAmmoForOneShot()
            << Term::color( Term::fg::reset )
            << Term::color( Term::style::reset );
    }
}

std::string WeaponWriter::informationWeaponType() const
{
    switch (weapon_->weaponType())
    {
        case WeaponType::fist:
            return "poing";
        case WeaponType::meleeWeapon:
            return "arme de mélée";
        case WeaponType::fireArm:
            return "arme à feu";
        default:
            return "";
    }
}