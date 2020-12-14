/*!
    * \file MessageWriter.cpp
*/

#include "MessageWriter.h"

#include <iostream>
#include <bits/stdc++.h> 
#include <boost/algorithm/string.hpp> 

#include "../color.h"
#include "../Message/Pause.h"

MessageWriter::MessageWriter
( 
    const Player* const player,
    const Plug* const plug,
    const MessageData& messageData 
) :
    player_( player ),
    plug_( plug ),
    messageData_( messageData )
{}

void MessageWriter::writeName( const int& i ) const 
{
    if ( messageData_.name()[i] == "player" )
    {
        std::cout << "\n        " << BOLDGREEN << player_->pseudo() << RESET << BLUE;
    }
    else if ( messageData_.name()[i] == "plug" )
    {
        std::cout << "\n        " << BOLDRED << plug_->name() << RESET << BLUE;
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

void MessageWriter::writeOneMessage( const int& i) const
{
    if ( messageData_.token()[i] )
    {
        std::cout << "\n " << replaceToken( messageData_.dialog()[i] );
    }
    else
    {
        std::cout << "\n " << ( messageData_.dialog()[i] );
    }
    std::cout << RESET;
}

void MessageWriter::writeMessage() const
{
    for ( int i = 0; i < messageData_.name().size(); i++ )
    {
        Pause::pause();

        writeName(i);
        
        writeOneMessage(i);
    }
}

std::string MessageWriter::replaceToken( const std::string& str) const
{
    std::vector<std::string> vecResult; 
    boost::split(vecResult, str, boost::is_any_of("-*"), boost::token_compress_on); 
  
    std::string result;

    for (unsigned int i = 0; i < vecResult.size(); i++)
    {
        if ( vecResult[i] == "pseudo" )
        {
            result += player_->pseudo();
        }
        else if ( vecResult[i] == "plugName" )
        {
            result += plug_->name();
        }
        else if ( vecResult[i] == "money" )
        {
            result += std::to_string( plug_->price() );
        }
        else if ( vecResult[i] == "damage" )
        {
            result += std::to_string( player_->selectedWeapon().damageWeapon() );
        }
        else
        {
            result += vecResult[i];
        }
    } 

    return result;  
}
