#ifndef CUTTER_H
#define CUTTER_H

/*!
    * \file Cutter.h
*/

#include "Weapon.h"

#include "Languages.h"

class Cutter : public Weapon
{
    public:
        Cutter() :
            Weapon( data::Weapon::nameCutter, 15, WeaponType::meleeWeapon, data::Weapon::statementUseCutter )
        {

        }

        ~Cutter() override = default;
};

#endif