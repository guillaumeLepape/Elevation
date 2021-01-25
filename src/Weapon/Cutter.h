#ifndef CUTTER_H
#define CUTTER_H

/*!
    * \file Cutter.h
*/

#include "Weapon.h"

class Cutter : public Weapon
{
    public:
        Cutter() :
            Weapon( "Cutter", 10, WeaponType::meleeWeapon )
        {

        }

        ~Cutter() override = default;
};

#endif