/*!
    * \file Player.cpp
*/

#include "Player.h"

#include <iostream>
#include <cassert>
#include <algorithm>

#include "WeaponFactory.h"

Player::Player( const std::string& pseudo, const std::string& id, const int& nbLevelSuceeded ) :
    Entity( pseudo, MAX_LIFE_POINTS_PLAYER, MAX_LIFE_POINTS_PLAYER ),
    id_( id ),
    nbLevelSuceeded_( nbLevelSuceeded ),
    money_(200),
    weapons_( 1, new Fist() )
{

}

Player::Player
( 
    const std::string& pseudo, 
    const std::string& id,
    const int& nbLevelSuceeded,
    const int& nbLifePoints,
    const int& money,
    const std::vector<const Weapon*>& weapons
) :
    Entity( pseudo, nbLifePoints, MAX_LIFE_POINTS_PLAYER ),
    id_( id ),
    nbLevelSuceeded_( nbLevelSuceeded ),
    money_(money),
    weapons_( weapons )
{

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
        { "weapons", jsonWeaponArray }
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
        weapons
    );

    return player;
} 
