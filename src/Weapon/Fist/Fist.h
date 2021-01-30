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
            Weapon( data::Weapon::nameFist, 20, WeaponType::fist, data::Weapon::statementUseFist )
        {

        }

        Fist( const Fist& fist ) = delete;

        ~Fist() override = default;
};

#endif