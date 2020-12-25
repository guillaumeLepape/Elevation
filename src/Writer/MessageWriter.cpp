/*!
    * \file MessageWriter.cpp
*/

#include "MessageWriter.h"

// #include <iostream>

#include "Token.h"
#include "color.h"
#include "Pause.h"

MessageWriter::MessageWriter
(
    const nlohmann::json& jsonObject
) :
    messageData_( jsonObject )
{

}
        
MessageWriter::MessageWriter
( 
    const MessageData& messageData 
) :
    messageData_( messageData )
{

}

MessageWriter::MessageWriter
(
    const std::string& folderFromRoot,
    const std::string& fileName
) :
    messageData_( folderFromRoot, fileName )
{

}

void MessageWriter::writeName( const int& i ) const 
{
    if ( messageData_.tokenName()[i] == "player" )
    {
        std::cout << "\n        " << BOLDGREEN << messageData_.name()[i] << RESET << BLUE;
    }
    else if ( messageData_.tokenName()[i] == "plug" )
    {
        std::cout << "\n        " << BOLDRED << messageData_.name()[i]<< RESET << BLUE;
    }
    else if ( messageData_.tokenName()[i] == "description" )
    {
        std::cout << BOLDMAGENTA;
    }
    else if ( messageData_.tokenName()[i] == "action" )
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
    // if ( messageData_.token()[i] )
    // {
    //     std::cout << "\n " << Token::replace( messageData_.dialog()[i], player_, plug_ );
    // }
    // else
    // {
    //     std::cout << "\n " << ( messageData_.dialog()[i] );
    // }
    std::cout << "\n " << ( messageData_.dialog()[i] );
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
