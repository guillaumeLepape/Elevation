/*!
    * \file Plug.cpp
*/

#include "Plug.h"

Plug::Plug( const std::string& name, const int& price, const int& nbLifePoints, const Weapon& weapon ) : 
    Entity( name, nbLifePoints ),
    price_(price), 
    weapon_(weapon)
{
    
}