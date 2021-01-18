#ifndef WEAPON_H
#define WEAPON_H

/*!
    * \file Weapon.h
*/

#include <string>

#include <nlohmann/json.hpp>

enum class WeaponType
{
    empty = -1,
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

    protected:
        Weapon();
        Weapon
        ( 
            const std::string& name, 
            const int& damageWeapon,
            WeaponType weaponType
        );
        
    public:
        virtual ~Weapon();

        const std::string& name() const { return name_; }
        const int& damageWeapon() const { return damageWeapon_; }
        const WeaponType& weaponType() const { return weaponType_; }

        nlohmann::json writeJson() const;
};

#endif