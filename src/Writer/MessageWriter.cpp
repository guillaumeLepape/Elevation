/*!
    * \file MessageWriter.cpp
*/

#include "MessageWriter.h"

#include "Token.h"
#include "Pause.h"

#include <cpp-terminal/terminal.h>

MessageWriter::MessageWriter
(
    const nlohmann::json& jsonObject
) :
    messageData_( jsonObject )
{

}

MessageWriter::MessageWriter
(
    const std::vector<std::tuple<NameSpeaker, std::string>>& message,
    const std::string& pseudo,
    const std::string& plugName
) :
    messageData_( message, pseudo, plugName )
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
    if ( messageData_.tokenName()[i] == NameSpeaker::player )
    {
        std::cout << "\n        " 
            << Term::color( Term::fg::green )
            << Term::color( Term::style::bold )
            << messageData_.name()[i] 
            << Term::color( Term::fg::reset )
            << Term::color( Term::style::reset );

        std::cout << Term::color( Term::fg::blue )
            << Term::color( Term::style::bold );
    }
    else if ( messageData_.tokenName()[i] == NameSpeaker::plug )
    {
        std::cout << "\n        " 
            << Term::color( Term::fg::red )
            << Term::color( Term::style::bold ) 
            << messageData_.name()[i]
            << Term::color( Term::fg::reset )
            << Term::color( Term::style::reset );

        std::cout << Term::color( Term::fg::blue )
            << Term::color( Term::style::bold );   
    }
    else if ( messageData_.tokenName()[i] == NameSpeaker::description )
    {
        std::cout << Term::color( Term::fg::magenta )
            << Term::color( Term::style::bold ) ;
    }
    else if ( messageData_.tokenName()[i] == NameSpeaker::action )
    {
        std::cout << Term::color( Term::fg::yellow )
            << Term::color( Term::style::bold ) ;
    }
    else
    {
        assert( false );
    }
}

void MessageWriter::writeOneMessage( const int& i) const
{
    std::cout << "\n " << ( messageData_.dialog()[i] );
    std::cout << Term::color( Term::fg::reset )
        << Term::color( Term::style::reset );
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
