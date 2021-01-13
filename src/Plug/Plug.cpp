/*!
    * \file Plug.cpp
*/

#include "Plug.h"

Plug::Plug( const std::string& name, const int& price, const int& lifePoints, const Weapon& weapon ) : 
    name_(name), price_(price), lifePoints_(lifePoints), weapon_(weapon)
{
    
}