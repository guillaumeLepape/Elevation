#ifndef WEAPON_H
#define WEAPON_H

/*!
    * \file Weapon.h
*/

#include <string>

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
        std::string defaultNameUseWeapon_;
        WeaponType weaponType_;

    public:
        Weapon
        ( 
            const std::string& name, 
            const int& damageWeapon,
            WeaponType weaponType
        ) :
            name_( name ),
            damageWeapon_( damageWeapon ),
            weaponType_( weaponType )
        {
            defaultNameUseWeapon_ = "use";
            char firstLetter = std::toupper( name[0] );
            defaultNameUseWeapon_ += firstLetter;
            defaultNameUseWeapon_ += name.substr(1, name.length());
        }

        const std::string& name() const { return name_; }
        const int& damageWeapon() const { return damageWeapon_; }
        const std::string& nameUseWeapon() const { return defaultNameUseWeapon_; }
        const WeaponType& weaponType() const { return weaponType_; }
};

#endif