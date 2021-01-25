#ifndef WEAPON_HANDLER_H
#define WEAPON_HANDLER_H

/*!
    * \file WeaponInventory.h
*/

#include <memory>
#include <vector>
#include "Weapon.h"

class WeaponInventory : public std::vector<std::shared_ptr<Weapon>>
{
    public:
        WeaponInventory( const int& size, std::shared_ptr<Weapon> weapon );
        WeaponInventory( const std::vector<std::shared_ptr<Weapon>>& weapon );

        WeaponInventory( const WeaponInventory& weaponInventory );

        ~WeaponInventory();

        void addWeapon( std::shared_ptr<Weapon> weapon );
        void deleteWeapon( const std::string& nameWeapon );
        void deleteWeapon( const Weapon& weapon );
        const Weapon* weaponFromName( const std::string& nameWeapon ) const;
        bool containWeaponType( const WeaponType& weaponType ) const;
};

#endif