#ifndef FIRE_ARM_H
#define FIRE_ARM_H

/*!
    * \file FireArm.h
*/

#include "Weapon.h"

#include "Languages.h"

class FireArm : public Weapon
{
    private:
        mutable int nbAmmo_;

    protected:
        FireArm
        ( 
            const std::string& name, 
            const int& damageWeapon,
            const int& nbAmmo,
            const std::string& statement
        ) :
            Weapon( name, damageWeapon, WeaponType::fireArm, statement ),
            nbAmmo_(nbAmmo)
        {

        }    

    public:
        ~FireArm() override {}

        nlohmann::json writeJson() const override
        {
            return 
            {
                { "name", name() },
                { "nbAmmo", nbAmmo_ }
            };
        }

        void attack( Entity* const entity ) const override
        {
            // if the player has at least one ammo, she can attack 
            if ( nbAmmo_ > 0 )
            {   
                Weapon::attack( entity );
                nbAmmo_--;
            }
        }

        const int& nbAmmo() const { return nbAmmo_; }   
};

#endif