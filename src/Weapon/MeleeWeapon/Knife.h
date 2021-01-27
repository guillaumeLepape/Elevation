#ifndef KNIFE_H
#define KNIFE_H

/*!
    * \file Knife.h
*/

#include "Weapon.h"

#include "Languages.h"

class Knife : public Weapon
{
    public: 
        Knife() :
            Weapon( "Couteau", 30, WeaponType::meleeWeapon, data::Weapon::statementUseKnife )
        {

        }

        ~Knife() override = default;
};

#endif