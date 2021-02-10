#ifndef HEROINE_H
#define HEROINE_H

/*!
    * \file Heroine.h
*/

#include "Weapon.h"

#include "Languages.h"

class Heroine : public Weapon
{
    public:
        Heroine() : 
            Weapon
            ( 
                data::Weapon::nameHeroine, 
                50, 
                WeaponType::meleeWeapon, 
                ""
            )
        {}

        ~Heroine() override = default;
};

#endif 