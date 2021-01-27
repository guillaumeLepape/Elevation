#ifndef WEAPON_H
#define WEAPON_H

/*!
    * \file Weapon.h
*/

#include <nlohmann/json.hpp>

#include "Entity.h"

enum class WeaponType
{
    fist = 0,
    meleeWeapon = 1,
    fireArm = 2
};

class Weapon 
{
    private: 
        std::string name_;
        int damageWeapon_;
        WeaponType weaponType_;
        const std::string statement_;

    protected:
        Weapon();
        Weapon
        ( 
            const std::string& name, 
            const int& damageWeapon,
            WeaponType weaponType,
            const std::string& statement
        );
        
    public:
        virtual ~Weapon() = default;

        const std::string& name() const { return name_; }
        const int& damageWeapon() const { return damageWeapon_; }
        const WeaponType& weaponType() const { return weaponType_; }
        const std::string& statement() const { return statement_; }

        friend bool operator==( const Weapon& weapon1, const Weapon& weapon2 );

        virtual nlohmann::json writeJson() const;

        virtual void attack( Entity* const entity ) const;
};

#endif