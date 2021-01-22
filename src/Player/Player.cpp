/*!
    * \file Player.cpp
*/

#include "Player.h"

#include <iostream>
#include <cassert>
#include <algorithm>

#include "WeaponFactory.h"

Player::Player( const std::string& pseudo, const std::string& id, const int& nbLevelSuceeded ) :
    pseudo_( pseudo ),
    id_( id ),
    nbLevelSuceeded_( nbLevelSuceeded ),
    nbLifePoints_(MAX_LIFE_POINTS),
    money_(200),
    weapons_( 1, Fist() ),
    selectedWeapon_(0),
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
    const std::vector<Weapon>& weapons,
    const int& price
) :
    pseudo_( pseudo ),
    id_( id ),
    nbLevelSuceeded_( nbLevelSuceeded ),
    nbLifePoints_(nbLifePoints),
    money_(money),
    weapons_( weapons ),
    selectedWeapon_(0),
    price_(price)
{

}

void Player::changeWeapon( const std::string& nameWeapon )
{
    for ( int i = 0; i < weapons_.size(); i++ )
    {
        if ( weapons_[i].name() == nameWeapon )
        {
            selectedWeapon_ = i;
        }
    }
}


const Weapon& Player::weaponFromName( const std::string& nameWeapon ) const
{
    for ( auto w = weapons_.cbegin(); w != weapons_.cend(); w++ )
    {
        if ( w->name() == nameWeapon )
        {
            return *w;
        }
    }

    assert(false);
} 

void Player::addWeapon( const Weapon& weapon )
{
    auto it = std::find( weapons_.cbegin(), weapons_.cend(), weapon );
    // If this condition is true, weapon is not in weapons_ so add it and sort the weapons_ vector
    if ( it == weapons_.cend() )
    {
        weapons_.push_back( weapon );
        // sort on the number of damage Weapon
        std::sort( weapons_.begin(), weapons_.end(), 
            []( const Weapon& weapon1, const Weapon& weapon2 ) -> bool
        {
            return weapon1.damageWeapon() < weapon2.damageWeapon(); 
        });
    }
}


void Player::deleteWeapon( const std::string& nameWeapon ) 
{
    auto x = [&nameWeapon]( const Weapon& weapon ) { return nameWeapon == weapon.name(); };

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

bool Player::containWeaponType( WeaponType weaponType )
{
    for ( auto w = weapons_.cbegin(); w != weapons_.cend(); w++ )
    {
        if ( w->weaponType() == weaponType )
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
            w->writeJson()
        );
    }

    nlohmann::json jsonObjectOutput
    {
        { "pseudo", pseudo_ },
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
    std::vector<Weapon> weapons;
    for ( auto wJson = jsonInput["weapons"].cbegin(); wJson != jsonInput["weapons"].cend(); wJson++ )
    {
        weapons.push_back
        (
            *( WeaponFactory::newWeapon( (*wJson)["name"] ).get() )
        );
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
