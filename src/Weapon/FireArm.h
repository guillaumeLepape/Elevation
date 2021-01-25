#ifndef FIRE_ARM_H
#define FIRE_ARM_H

/*!
    * \file FireArm.h
*/

#include "Weapon.h"

class FireArm : public Weapon
{
    private:
        mutable int nbAmmo_;

    protected:
        FireArm
        ( 
            const std::string& name, 
            const int& damageWeapon,
            const int& nbAmmo
        ) :
            Weapon( name, damageWeapon, WeaponType::fireArm ),
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
            Weapon::attack( entity );
            nbAmmo_--;
        }

        const int& nbAmmo() const { return nbAmmo_; }   
};

#endif