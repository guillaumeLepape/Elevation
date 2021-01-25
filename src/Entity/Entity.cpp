/*!
    * \file Entity.cpp
*/

#include "Entity.h"

Entity::Entity( const std::string& name, const int& nbLifePoints ) :
    name_( name ),
    nbLifePoints_( nbLifePoints ),
    maxNbLifePoints_( nbLifePoints )
{

}

