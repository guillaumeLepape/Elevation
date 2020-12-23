/*!
    * \file Player.cpp
*/

#include "Player.h"

#include <iostream>
#include <cassert>

Player::Player( const Result& result ) : 
    result_( result ),
    nbLifePoints_(100),
    money_(200),
    dead_(false),
    weapons_( 1, Weapon("fist", 20, "Cognez !") ),
    selectedWeapon_(0),
    price_(0)
{

}

void Player::printState()
{
    std::cout << "\n" << result_.pseudo_;
    std::cout << "\n" << nbLifePoints_;
    std::cout << "\n" << money_;
    std::cout << "\n";
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
