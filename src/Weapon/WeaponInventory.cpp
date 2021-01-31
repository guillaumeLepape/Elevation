/*!
    * \file WeaponInventory.cpp
*/

#include "WeaponInventory.h"

WeaponInventory::WeaponInventory( const int& size, const Weapon* weapon )
{
    for ( int i = 0; i < size; i++ )
    {    
        std::list<std::unique_ptr<const Weapon>>::emplace_back( weapon );
    }
}

WeaponInventory::WeaponInventory( const std::list<const Weapon*>& weapons )
{
    for ( auto w = weapons.cbegin(); w != weapons.cend(); w++ )
    {
        std::list<std::unique_ptr<const Weapon>>::emplace_back( *w );
    }
}

bool WeaponInventory::addWeapon( const Weapon* weapon )
{
    auto it = std::find_if( 
        std::list<std::unique_ptr<const Weapon>>::cbegin(), 
        std::list<std::unique_ptr<const Weapon>>::cend(), 
        [&weapon]( const std::unique_ptr<const Weapon>& lWeapon )
        {
            return *(weapon) == *(lWeapon);
        } 
    );

    bool present = (it != std::list<std::unique_ptr<const Weapon>>::cend());
    
    // If this condition is true, weapon is not in weapons_ so add it and sort the weapons_ vector
    if ( !present )
    {
        std::list<std::unique_ptr<const Weapon>>::emplace_back( weapon );
        // sort on the number of damage Weapon

        std::list<std::unique_ptr<const Weapon>>::sort(
            []( const std::unique_ptr<const Weapon>& weapon1, 
                const std::unique_ptr<const Weapon>& weapon2 ) -> bool
        {
            if ( weapon1->weaponType() == weapon2->weaponType() )
            {
                return weapon1->damageWeapon() < weapon2->damageWeapon();
            }
            else
            {
                return weapon1->weaponType() < weapon2->weaponType(); 
            }
        });
    }

    return present;
}

void WeaponInventory::deleteWeapon( const std::string& nameWeapon )
{
    std::list<std::unique_ptr<const Weapon>>::remove_if
    (
        [&nameWeapon]( const std::unique_ptr<const Weapon>& weapon ) -> bool
        {
            return nameWeapon == weapon->name();
        }
    );
}

void WeaponInventory::deleteWeapon( const Weapon& weapon )
{
    deleteWeapon( weapon.name() );
}

// const Weapon* WeaponInventory::weaponFromName( const std::string& nameWeapon ) const
// {
//     for ( 
//         auto w = std::list<std::unique_ptr<const Weapon>>::cbegin(); 
//         w != std::list<std::unique_ptr<const Weapon>>::cend(); 
//         w++ )
//     {
//         if ( (*w)->name() == nameWeapon )
//         {
//             return &(**w);
//         }
//     }

//     assert(false);
// }

bool WeaponInventory::containWeaponType( const WeaponType& weaponType ) const
{
    for ( 
        auto w = std::list<std::unique_ptr<const Weapon>>::cbegin(); 
        w != std::list<std::unique_ptr<const Weapon>>::cend(); 
        w++ 
    )
    {
        if ( (*w)->weaponType() == weaponType )
        {
            return true;
        }
    }

    return false;
}