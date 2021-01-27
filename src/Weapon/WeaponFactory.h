#ifndef WEAPON_FACTORY_H
#define WEAPON_FACTORY_H

/*!
    * \file WeaponFactory.h
*/

#include "Fist.h"
#include "Knife.h"
#include "Katana.h"
#include "Cutter.h"
#include "Hammer.h"
#include "Ninemm.h"
#include "AK47.h"

#include "WeaponFistCombo.h"

class WeaponFactory
{
    public:
        static const Weapon* newWeapon( const std::string& nameWeapon )
        {
            if ( nameWeapon == data::Weapon::nameFist ) { return new Fist(); }
            if ( nameWeapon == data::Weapon::nameKnife ) { return new Knife(); }
            if ( nameWeapon == data::Weapon::nameKatana ) { return new Katana(); }
            if ( nameWeapon == data::Weapon::nameCutter ) { return new Cutter(); }
            if ( nameWeapon == data::Weapon::nameHammer ) { return new Hammer(); }
            assert(false);

        }

        static const Weapon* newWeaponFistCombo( const std::string& nameWeapon )
        {
            return new WeaponFistCombo( *newWeapon( nameWeapon ) );
        }

        static const Weapon* newFireArm( const std::string& nameWeapon, const int& nbAmmo )
        {
            if ( nameWeapon == data::Weapon::nameNinemm ) { return new Ninemm( nbAmmo ); }
            if ( nameWeapon == data::Weapon::nameAK47 ) { return new AK47( nbAmmo ); }
            assert(false);
        }
};

#endif