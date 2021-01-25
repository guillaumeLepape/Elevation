/*!
    * \file Player.cpp
*/

#include "Player.h"

#include <iostream>
#include <cassert>
#include <algorithm>

#include "WeaponFactory.h"

Player::Player( const std::string& pseudo, const std::string& id, const int& nbLevelSuceeded ) :
    Entity( pseudo, 100 ),
    id_( id ),
    nbLevelSuceeded_( nbLevelSuceeded ),
    money_(200),
    weapons_( 1, new Fist() ),
    price_(0)
{

}

Player::Player
( 
    const std::string& pseudo, 
    const std::string& id,
    const int& nbLevelSuceeded,
    const int& nbLifePoints,
    const int& money,
    const std::vector<const Weapon*>& weapons,
    const int& price
) :
    Entity( pseudo, nbLifePoints ),
    id_( id ),
    nbLevelSuceeded_( nbLevelSuceeded ),
    money_(money),
    weapons_( weapons ),
    price_(price)
{

}


const Weapon* Player::weaponFromName( const std::string& nameWeapon ) const
{
    for ( auto w = weapons_.cbegin(); w != weapons_.cend(); w++ )
    {
        if ( (*w)->name() == nameWeapon )
        {
            return &(**w);
        }
    }

    assert(false);
} 

void Player::addWeapon( const Weapon* const weapon )
{
    auto it = std::find_if( 
        weapons_.cbegin(), 
        weapons_.cend(), 
        [&weapon]( const Weapon* const lWeapon )
        {
            return *(weapon) == *(lWeapon);
        } 
    );
    // If this condition is true, weapon is not in weapons_ so add it and sort the weapons_ vector
    if ( it == weapons_.cend() )
    {
        weapons_.push_back( weapon );
        // sort on the number of damage Weapon
        std::sort( weapons_.begin(), weapons_.end(), 
            []( const Weapon* const weapon1, const Weapon* const weapon2 ) -> bool
        {
            return weapon1->damageWeapon() < weapon2->damageWeapon(); 
        });
    }
}


void Player::deleteWeapon( const std::string& nameWeapon ) 
{
    auto x = [&nameWeapon]( const Weapon* const weapon ) { return nameWeapon == weapon->name(); };

    weapons_.erase
    (
        std::remove_if
        ( 
            weapons_.begin(), 
            weapons_.end(), 
            x
        ),
        weapons_.end()
    );
}

void Player::deleteWeapon( const Weapon& weapon )
{
    deleteWeapon( weapon.name() );
}


bool Player::containWeaponType( WeaponType weaponType )
{
    for ( auto w = weapons_.cbegin(); w != weapons_.cend(); w++ )
    {
        if ( (*w)->weaponType() == weaponType )
        {
            return true;
        }
    }

    return false;
}

nlohmann::json Player::writeJson() const
{
    nlohmann::json jsonWeaponArray;
    for ( auto w = weapons_.cbegin(); w != weapons_.cend(); w++ )
    {
        jsonWeaponArray.push_back(
            (*w)->writeJson()
        );
    }

    nlohmann::json jsonObjectOutput
    {
        { "pseudo", name_ },
        { "id", id_ },
        { "nbLevelSuceeded", nbLevelSuceeded_ },
        { "nbLifePoints", nbLifePoints_ },
        { "money", money_ },
        { "weapons", jsonWeaponArray },
        { "price", price_ }
    };

    return jsonObjectOutput;
}

Player* Player::readJson( const nlohmann::json& jsonInput )
{   
    std::vector<const Weapon*> weapons;
    for ( auto wJson = jsonInput["weapons"].cbegin(); wJson != jsonInput["weapons"].cend(); wJson++ )
    {
        bool nbAmmoPresent = wJson->count("nbAmmo");
        if ( nbAmmoPresent  )
        {
            weapons.push_back( 
                WeaponFactory::newFireArm( (*wJson)["name"], (*wJson)["nbAmmo"] )
            );
        }
        else
        {
            weapons.push_back
            (
                WeaponFactory::newWeapon( (*wJson)["name"] )
            );
        }
    }

    Player* player = new Player
    ( 
        jsonInput["pseudo"],
        jsonInput["id"],
        jsonInput["nbLevelSuceeded"],
        jsonInput["nbLifePoints"],
        jsonInput["money"],
        weapons,
        jsonInput["price"]
    );

    return player;
} 