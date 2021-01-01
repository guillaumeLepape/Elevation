#ifndef WEAPON_H
#define WEAPON_H

/*!
    * \file Weapon.h
*/

#include <string>

class Weapon 
{
    private: 
        const std::string name_;
        const int damageWeapon_;
        std::string defaultNameUseWeapon_;

    public:
        Weapon
        ( 
            const std::string& name, 
            const int& damageWeapon 
        ) :
            name_( name ),
            damageWeapon_( damageWeapon )
        {
            defaultNameUseWeapon_ = "use";
            char firstLetter = std::toupper( name[0] );
            defaultNameUseWeapon_ += firstLetter;
            defaultNameUseWeapon_ += name.substr(1, name.length());
        }

        const std::string& name() const { return name_; }
        const int& damageWeapon() const { return damageWeapon_; }
        const std::string& nameUseWeapon() const { return defaultNameUseWeapon_; }
};

#endif