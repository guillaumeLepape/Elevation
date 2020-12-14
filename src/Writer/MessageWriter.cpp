/*!
    * \file MessageWriter.cpp
*/

#include "MessageWriter.h"

#include <iostream>
#include <bits/stdc++.h> 
#include <boost/algorithm/string.hpp> 

#include "../color.h"
#include "../Message/Pause.h"

MessageWriter::MessageWriter( const MessageData& messageData ) :
    messageData_( messageData )
{}

void MessageWriter::writeName( Player* player, Plug* plug, const int& i ) const 
{
    if ( messageData_.name()[i] == "player" )
    {
        std::cout << "\n        " << BOLDGREEN << player->pseudo() << RESET << BLUE;
    }
    else if ( messageData_.name()[i] == "plug" )
    {
        std::cout << "\n        " << BOLDRED << plug->name() << RESET << BLUE;
    }
    else if ( messageData_.name()[i] == "description" )
    {
        std::cout << BOLDMAGENTA;
    }
    else if ( messageData_.name()[i] == "action" )
    {
        std::cout << BOLDYELLOW;
    }
    else
    {
        assert( false );
    }
}

void MessageWriter::writeOneMessage( Player* player, Plug* plug, const int& i) const
{
    if ( messageData_.token()[i] )
    {
        std::cout << "\n " << replaceToken( player, plug, messageData_.dialog()[i] );
    }
    else
    {
        std::cout << "\n " << ( messageData_.dialog()[i] );
    }
    std::cout << RESET;
}

void MessageWriter::writeMessage( Player* player, Plug* plug ) const
{
    for ( int i = 0; i < messageData_.name().size(); i++ )
    {
        Pause::pause();

        writeName( player, plug, i );
        
        writeOneMessage( player, plug, i );
    }
}

std::string MessageWriter::replaceToken(Player* player, Plug* plug, const std::string& str) const
{
    std::vector<std::string> vecResult; 
    boost::split(vecResult, str, boost::is_any_of("-*"), boost::token_compress_on); 
  
    std::string result;

    for (unsigned int i = 0; i < vecResult.size(); i++)
    {
        if ( vecResult[i] == "pseudo" )
        {
            result += player->pseudo();
        }
        else if ( vecResult[i] == "plugName" )
        {
            result += plug->name();
        }
        else if ( vecResult[i] == "money" )
        {
            result += std::to_string( plug->price() );
        }
        else if ( vecResult[i] == "damage" )
        {
            result += std::to_string( player->selectedWeapon().damageWeapon() );
        }
        else
        {
            result += vecResult[i];
        }
    } 

    return result;  
}
