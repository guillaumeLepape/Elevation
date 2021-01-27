#ifndef WEAPON_HANDLER_H
#define WEAPON_HANDLER_H

/*!
    * \file WeaponInventory.h
*/

#include <vector>
#include "Weapon.h"

class WeaponInventory : public std::vector<const Weapon*>
{
    public:
        WeaponInventory( const int& size, const Weapon* weapon );
        WeaponInventory( const std::vector<const Weapon*>& weapon );

        WeaponInventory( const WeaponInventory& weaponInventory );

        ~WeaponInventory();

        bool addWeapon( const Weapon* weapon );
        void deleteWeapon( const std::string& nameWeapon );
        void deleteWeapon( const Weapon& weapon );
        const Weapon* weaponFromName( const std::string& nameWeapon ) const;
        bool containWeaponType( const WeaponType& weaponType ) const;
};

#endif