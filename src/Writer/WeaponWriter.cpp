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
        << "Nom : " << weapon_->name()
        << Term::color( Term::fg::reset )
        << Term::color( Term::style::reset );

    std::cout << "\n "
        << Term::color( Term::fg::magenta )
        << Term::color( Term::style::bold )
        << "Points d'attaque : " << weapon_->damageWeapon()
        << Term::color( Term::fg::reset )
        << Term::color( Term::style::reset );

    std::cout << "\n "
        << Term::color( Term::fg::magenta )
        << Term::color( Term::style::bold )
        << "Type : " << informationWeaponType()
        << Term::color( Term::fg::reset )
        << Term::color( Term::style::reset );

    if ( weapon_->weaponType() == WeaponType::fireArm )
    {
        std::cout << "\n "
        << Term::color( Term::fg::magenta )
        << Term::color( Term::style::bold )
        << "Nombre de munitions : " << ( (FireArm*) weapon_ )->nbAmmo()
        << Term::color( Term::fg::reset )
        << Term::color( Term::style::reset );
    }
}

std::string WeaponWriter::informationWeaponType() const
{
    switch (weapon_->weaponType())
    {
        case WeaponType::empty:
            return "vide";
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