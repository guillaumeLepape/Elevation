/*!
    * \file Weapon.cpp
*/

#include "Weapon.h"

Weapon::Weapon() :
    name_(""),
    damageWeapon_(0),
    weaponType_( WeaponType::empty )
{

}

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
    settingNameWeapon( name );
}

nlohmann::json Weapon::writeJson() const
{   
    return 
    {
        { "name", name_ },
        { "damageWeapon", damageWeapon_ },
        { "weaponType", weaponType_ }
    };
}   
