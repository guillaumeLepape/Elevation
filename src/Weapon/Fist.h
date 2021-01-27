#ifndef FIST_H
#define FIST_H

/*!
    * \file Fist.h
*/

#include "Weapon.h"

#include "Languages.h"

class Fist : public Weapon
{
    public:
        Fist() :
            Weapon( "Poing", 20, WeaponType::fist, data::Weapon::statementUseFist )
        {

        }

        ~Fist() override = default;
};

#endif