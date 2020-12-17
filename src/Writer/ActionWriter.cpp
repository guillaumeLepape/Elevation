/*!
    * \file ActionWriter.cpp
*/

#include "ActionWriter.h"

#include <iostream>

#include "../color.h"
#include "Pause.h"
#include "ReplaceToken.h"

ActionWriter::ActionWriter
( 
    const int& levelNumber, 
    const std::string& nameFile,
    const bool& inputOrNot
) :
    actionData_( levelNumber, nameFile ),
    inputOrNot_( inputOrNot )
{
    
}

void ActionWriter::writeAction( const Player* const player, const Plug* const plug ) const
{    
    if ( inputOrNot_ )
    {    
        std::cout << "\n " << YELLOWSIDEBAR << BOLDBLACK << actionData_.statement() << RESET << " : ";
    }   
    else
    {
        Pause::pause();
        std::cout << "\n " << BOLDYELLOW << ReplaceToken::replace( actionData_.statement(), player, plug ) << RESET;
    }
    
}