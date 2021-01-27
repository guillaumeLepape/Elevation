/*!
    * \file WeaponInventory.cpp
*/

#include "WeaponInventory.h"

WeaponInventory::WeaponInventory( const int& size, const Weapon* weapon ) :
    std::vector<const Weapon*>( size, weapon )
{

}

WeaponInventory::WeaponInventory( const std::vector<const Weapon*>& weapons ) :
    std::vector<const Weapon*>( weapons )
{

}

WeaponInventory::WeaponInventory( const WeaponInventory& weaponInventory ) :
    std::vector<const Weapon*>()
{
    for ( long unsigned int i = 0; i < weaponInventory.size(); i++ )
    {
        std::vector<const Weapon*>::push_back( new Weapon(*(weaponInventory[i])) );
    }
}

WeaponInventory::~WeaponInventory()
{
    
}

bool WeaponInventory::addWeapon( const Weapon* weapon )
{
    auto it = std::find_if( 
        std::vector<const Weapon*>::cbegin(), 
        std::vector<const Weapon*>::cend(), 
        [&weapon]( const Weapon* const lWeapon )
        {
            return *(weapon) == *(lWeapon);
        } 
    );

    bool present = (it != std::vector<const Weapon*>::cend());
    
    // If this condition is true, weapon is not in weapons_ so add it and sort the weapons_ vector
    if ( !present )
    {
        std::vector<const Weapon*>::push_back( weapon );
        // sort on the number of damage Weapon
        std::sort( std::vector<const Weapon*>::begin(), std::vector<const Weapon*>::end(), 
            []( const Weapon* const weapon1, const Weapon* const weapon2 ) -> bool
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
    auto lambdaSorter = [&nameWeapon]( const Weapon* weapon ) { return nameWeapon == weapon->name(); };

    std::vector<const Weapon*>::erase
    (
        std::remove_if
        ( 
            std::vector<const Weapon*>::begin(), 
            std::vector<const Weapon*>::end(), 
            lambdaSorter
        ),
        std::vector<const Weapon*>::end()
    );
}

void WeaponInventory::deleteWeapon( const Weapon& weapon )
{
    deleteWeapon( weapon.name() );
}

const Weapon* WeaponInventory::weaponFromName( const std::string& nameWeapon ) const
{
    for ( auto w = std::vector<const Weapon*>::cbegin(); w != std::vector<const Weapon*>::cend(); w++ )
    {
        if ( (*w)->name() == nameWeapon )
        {
            return &(**w);
        }
    }

    assert(false);
}

bool WeaponInventory::containWeaponType( const WeaponType& weaponType ) const
{
    for ( 
        auto w = std::vector<const Weapon*>::cbegin(); 
        w != std::vector<const Weapon*>::cend(); 
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