/*!
    * \file WeaponInventory.cpp
*/

#include "WeaponInventory.h"

WeaponInventory::WeaponInventory( const int& size, std::shared_ptr<Weapon> weapon ) :
    std::vector<std::shared_ptr<Weapon>>( size, weapon )
{

}

WeaponInventory::WeaponInventory( const std::vector<std::shared_ptr<Weapon>>& weapons ) :
    std::vector<std::shared_ptr<Weapon>>( weapons )
{

}

WeaponInventory::WeaponInventory( const WeaponInventory& weaponInventory )
{
    for ( long unsigned int i = 0; i < weaponInventory.size(); i++ )
    {
        std::vector<std::shared_ptr<Weapon>>::push_back( weaponInventory[i] );
    }
}

WeaponInventory::~WeaponInventory()
{
    
}

void WeaponInventory::addWeapon( std::shared_ptr<Weapon> weapon )
{
    auto lambda_finder = [&weapon]( std::shared_ptr<Weapon> lWeapon ) 
    { 
        return *(weapon.get()) == *(lWeapon.get());
    };

    bool found = std::find_if
    (
        std::vector<std::shared_ptr<Weapon>>::cbegin(), 
        std::vector<std::shared_ptr<Weapon>>::cend(), 
        lambda_finder
    ) != std::vector<std::shared_ptr<Weapon>>::cend();

    // If this condition is true, weapon is not in std::vector<const Weapon*>
    // so add it and sort the std::vector<const Weapon*> vector
    if ( !found )
    {
        std::vector<std::shared_ptr<Weapon>>::push_back( weapon );
        // sort on the number of damage Weapon
        std::sort( 
            std::vector<std::shared_ptr<Weapon>>::begin(), 
            std::vector<std::shared_ptr<Weapon>>::end(), 
            []( std::shared_ptr<Weapon> weapon1, std::shared_ptr<Weapon> weapon2 ) -> bool
        {
            return weapon1.get()->damageWeapon() < weapon2.get()->damageWeapon(); 
        });
    }
}

void WeaponInventory::deleteWeapon( const std::string& nameWeapon )
{
    auto lambdaSorter = [&nameWeapon]( std::shared_ptr<Weapon> weapon ) { return nameWeapon == weapon->name(); };

    std::vector<std::shared_ptr<Weapon>>::erase
    (
        std::remove_if
        ( 
            std::vector<std::shared_ptr<Weapon>>::begin(), 
            std::vector<std::shared_ptr<Weapon>>::end(), 
            lambdaSorter
        ),
        std::vector<std::shared_ptr<Weapon>>::end()
    );
}

void WeaponInventory::deleteWeapon( const Weapon& weapon )
{
    deleteWeapon( weapon.name() );
}

const Weapon* WeaponInventory::weaponFromName( const std::string& nameWeapon ) const
{
    for ( 
        auto w = std::vector<std::shared_ptr<Weapon>>::cbegin(); 
        w != std::vector<std::shared_ptr<Weapon>>::cend(); 
        w++ 
    )
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
        auto w = std::vector<std::shared_ptr<Weapon>>::cbegin(); 
        w != std::vector<std::shared_ptr<Weapon>>::cend(); 
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