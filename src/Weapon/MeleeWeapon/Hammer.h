#ifndef HAMMER_H
#define HAMMER_H

/*!
    * \file Hammer.h
*/

#include "Hammer.h"

class Hammer : public Weapon
{   
    public: 
        Hammer() :
            Weapon( "Marteau", 40, WeaponType::meleeWeapon, data::Weapon::statementUseHammer )
        {

        }

        ~Hammer() override = default;
};

#endif