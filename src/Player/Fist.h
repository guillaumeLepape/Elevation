#ifndef FIST_H
#define FIST_H

/*!
    * \file Fist.h
*/

#include "Weapon.h"

class Fist : public Weapon
{
    public:
        Fist() :
            Weapon( "Poing", 20, WeaponType::fist )
        {

        }
};

#endif