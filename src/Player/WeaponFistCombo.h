#ifndef WEAPON_FIST_COMBO_H
#define WEAPON_FIST_COMBO_H

/*!
    * \file WeaponFistCombo.h
*/

#include "Weapon.h"

class WeaponFistCombo : public Weapon
{
    public:
        WeaponFistCombo( const Weapon& weapon ) :
            Weapon( weapon.name() + "FistCombo", weapon.damageWeapon()/2, weapon.weaponType() )
        {

        }
};

#endif