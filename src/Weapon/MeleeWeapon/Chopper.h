#ifndef CHOPPER_H
#define CHOPPER_H

/*!
    * \file Chopper.h
*/

class Chopper : public Weapon
{
    public:
        Chopper() :
            Weapon
            (
                data::Weapon::nameChopper, 
                80, 
                WeaponType::meleeWeapon, 
                data::Weapon::statementUseChopper
            )
        {

        }

        ~Chopper() override = default;
};

#endif