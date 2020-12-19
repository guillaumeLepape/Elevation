/*!
    * \file MessageWriter.cpp
*/

#include "MessageWriter.h"

#include <iostream>

#include "Token.h"
#include "../color.h"
#include "Pause.h"

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
        std::cout << "\n " << Token::replace( messageData_.dialog()[i], player_, plug_ );
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

// std::string MessageWriter::Token( const std::string& str) const
// {
    
// }
