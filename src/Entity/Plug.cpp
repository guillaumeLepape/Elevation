/*!
    * \file Plug.cpp
*/

#include "Plug.h"

Plug::Plug
( 
    const std::string& name, 
    const int& nbLifePoints, 
    Weapon* const weapon 
) : 
    Entity( name, nbLifePoints ),
    weapon_(weapon)
{
    
}