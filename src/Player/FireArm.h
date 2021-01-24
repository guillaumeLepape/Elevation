#ifndef FIRE_ARM_H
#define FIRE_ARM_H

/*!
    * \file FireArm.h
*/

#include "Weapon.h"

class FireArm : public Weapon
{
    private:
        int nbAmmo_;

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
        virtual ~FireArm() {}

        virtual nlohmann::json writeJson() const override
        {
            return 
            {
                { "name", name() },
                { "nbAmmo", nbAmmo_ }
            };
        }

        const int& nbAmmo() const { return nbAmmo_; }   
};

#endif