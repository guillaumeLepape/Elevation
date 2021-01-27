#ifndef WEAPON_FACTORY_H
#define WEAPON_FACTORY_H

/*!
    * \file WeaponFactory.h
*/

#include "NoWeapon.h"
#include "Fist.h"
#include "Knife.h"
#include "Katana.h"
#include "Cutter.h"
#include "Hammer.h"
#include "Ninemm.h"

#include "WeaponFistCombo.h"

class WeaponFactory
{
    public:
        static const Weapon* newWeapon( const std::string& nameWeapon )
        {
            if ( nameWeapon == "NoWeapon" ) { return new NoWeapon(); }
            if ( nameWeapon == "Poing" ) { return new Fist(); }
            if ( nameWeapon == "Couteau" ) { return new Knife(); }
            if ( nameWeapon == "Katana" ) { return new Katana(); }
            if ( nameWeapon == "Cutter" ) { return new Cutter(); }
            if ( nameWeapon == "Marteau" ) { return new Hammer(); }
            assert(false);

        }

        static const Weapon* newWeaponFistCombo( const std::string& nameWeapon )
        {
            return new WeaponFistCombo( *newWeapon( nameWeapon ) );
        }

        static const FireArm* newFireArm( const std::string& nameWeapon, const int& nbAmmo )
        {
            if ( nameWeapon == "9mm" ) { return new Ninemm( nbAmmo ); }
            assert(false);
        }
};

#endif