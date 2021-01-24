#ifndef KATANA_H
#define KATANA_H

/*!
    * \file Katana.h
*/

#include "Weapon.h"

class Katana : public Weapon
{   
    public:
        Katana() :
            Weapon( "Katana", 50, WeaponType::meleeWeapon )
        {

        }

        ~Katana() override = default;
};

#endif