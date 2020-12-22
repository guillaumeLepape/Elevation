/*!
    * \file ActionWriter.cpp
*/

#include "ActionWriter.h"

#include "color.h"
#include "Pause.h"
#include "Token.h"

ActionWriter::ActionWriter( const nlohmann::json& jsonObject ) :
    actionData_( jsonObject )
{

}

ActionWriter::ActionWriter( const ActionData& actionData ) :
    actionData_( actionData )
{

}

ActionWriter::ActionWriter( const std::string& folderFromRoot, const std::string& nameFile ) :
    actionData_( folderFromRoot, nameFile )
{

}

void ActionWriter::writeStatement( const Player* const player, const Plug* const plug ) const
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