#ifndef KNIFE_H
#define KNIFE_H

/*!
    * \file Knife.h
*/

#include "Weapon.h"

class Knife : public Weapon
{
    public: 
        Knife() :
            Weapon( "Couteau", 30, WeaponType::meleeWeapon )
        {

        }

        ~Knife() override = default;
};

#endif