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
        std::string defaultNameUseWeapon_;
        WeaponType weaponType_;

        void settingNameWeapon( const std::string& name )
        {
            if ( weaponType_ != WeaponType::empty ) 
            {
                defaultNameUseWeapon_ = "use";
                char firstLetter = std::toupper( name[0] );
                defaultNameUseWeapon_ += firstLetter;
                defaultNameUseWeapon_ += name.substr(1, name.length());
            }
        }

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
        const std::string& nameUseWeapon() const { return defaultNameUseWeapon_; }
        const WeaponType& weaponType() const { return weaponType_; }

        nlohmann::json writeJson() const;
};

#endif