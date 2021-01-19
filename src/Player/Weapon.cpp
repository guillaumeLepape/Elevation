/*!
    * \file Weapon.cpp
*/

#include "Weapon.h"

Weapon::Weapon
( 
    const std::string& name, 
    const int& damageWeapon,
    WeaponType weaponType
) :
    name_( name ),
    damageWeapon_( damageWeapon ),
    weaponType_( weaponType )
{
    
}

Weapon::~Weapon()
{

}


nlohmann::json Weapon::writeJson() const
{   
    return 
    {
        { "name", name_ }
    };
}   
