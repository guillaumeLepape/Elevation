/*!
    * \file ActionWriter.cpp
*/

#include "ActionWriter.h"

#include "../color.h"
#include "Pause.h"
#include "Token.h"

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

void ActionWriter::writeStatement( const Player* const player, const Plug* const plug ) const
{    
    if ( inputOrNot_ )
    {           
        std::cout << "\n " << YELLOWSIDEBAR << BOLDBLACK;
        if ( actionData_.tokenStatement() )
        {
            std::cout << Token::replace( actionData_.statement(), player, plug );
        }
        else
        {
            std::cout << actionData_.statement();
        }
        std::cout << RESET << " : ";
    }
    else
    {
       
    }
    
}

void ActionWriter::writeResult( const Player* const player, const Plug* const plug ) const 
{
    Pause::pause();
    std::cout << "\n " << BOLDYELLOW;
    if ( actionData_.tokenResult() ) 
    {
        std::cout << Token::replace( actionData_.result(), player, plug ); 
    }
    else 
    {
        std::cout << actionData_.result();
    }
    std::cout << RESET;
}