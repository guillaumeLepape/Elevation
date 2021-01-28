/*!
    * \file Plug.cpp
*/

#include "Plug.h"

Plug::Plug
( 
    const std::string& name, 
    const int& nbLifePoints, 
    const Weapon* weapon 
) : 
    Entity( name, nbLifePoints, nbLifePoints ),
    weapon_(weapon)
{
    
}

void Plug::changeWeapon( const Weapon* newWeapon )
{
    weapon_ = newWeapon;
}