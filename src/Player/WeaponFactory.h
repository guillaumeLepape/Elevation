#ifndef WEAPON_FACTORY_H
#define WEAPON_FACTORY_H

/*!
    * \file WeaponFactory.h
*/

#include "NoWeapon.h"
#include "Fist.h"
#include "Knife.h"
#include "Katana.h"

#include "WeaponFistCombo.h"

class WeaponFactory
{
    public:
        static std::unique_ptr<Weapon> newWeapon( const std::string& nameWeapon )
        {
            if ( nameWeapon == "noWeapon" ) { return std::make_unique<NoWeapon>(); }
            if ( nameWeapon == "fist" ) { return std::make_unique<Fist>(); }
            if ( nameWeapon == "knife" ) { return std::make_unique<Knife>(); }
            if ( nameWeapon == "katana" ) { return std::make_unique<Katana>(); }
            assert(false);

        }

        static std::unique_ptr<Weapon> newWeaponFistCombo( const std::string& nameWeapon )
        {
            return std::make_unique<WeaponFistCombo>( *(newWeapon( nameWeapon ).get()) );
        }
};

#endif