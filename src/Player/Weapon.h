#ifndef WEAPON_H
#define WEAPON_H

/*!
    * \file Weapon.h
*/

#include <string>

class Weapon 
{
    private: 
        std::string name_;
        int damageWeapon_;
        std::string statementAction_;

    public:
        Weapon
        ( 
            const std::string& name, 
            const int& damageWeapon, 
            const std::string& statementAction
        ) :
            name_( name ),
            damageWeapon_( damageWeapon ),
            statementAction_( statementAction )
        {}

        const std::string& name() const { return name_; }
        const int& damageWeapon() const { return damageWeapon_; }
        const std::string& statementAction() const { return statementAction_; }
};

#endif