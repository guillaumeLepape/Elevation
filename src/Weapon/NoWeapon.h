#ifndef NO_WEAPON_H
#define NO_WEAPON_H

/*!
    * \file NoWeapon.h
*/

#include "Weapon.h"

class NoWeapon : public Weapon
{
    public: 
        NoWeapon() :
            Weapon( "NoWeapon", 0, WeaponType::empty, "" )
        {

        }

        ~NoWeapon() override = default;
};

#endif