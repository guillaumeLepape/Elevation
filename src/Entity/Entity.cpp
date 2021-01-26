/*!
    * \file Entity.cpp
*/

#include "Entity.h"

#include <iomanip>

Entity::Entity( const std::string& name, const int& nbLifePoints ) :
    name_( name ),
    nbLifePoints_( nbLifePoints ),
    maxNbLifePoints_( nbLifePoints )
{

}

std::string Entity::healthBar() const
{
    return std::to_string( nbLifePoints_ ) + "/" + std::to_string( maxNbLifePoints_ ) + " points de vie.";
}
