#ifndef KATANA_H
#define KATANA_H

/*!
    * \file Katana.h
*/

#include "Weapon.h"

#include "Languages.h"

class Katana : public Weapon
{   
    public:
        Katana() :
            Weapon( "Katana", 50, WeaponType::meleeWeapon, data::Weapon::statementUseKatana )
        {

        }

        ~Katana() override = default;
};

#endif