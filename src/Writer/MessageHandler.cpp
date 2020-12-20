/*!
    * \file MessageHandler.cpp
*/

#include "MessageHandler.h"

MessageHandler::MessageHandler
( 
    const int& levelNumber,
    const Player* const player, 
    const Plug* const plug,
    int indexMessage
) :
    messagesData_( levelNumber ),
    player_( player ),
    plug_( plug ),
    indexMessage_( indexMessage )
{

}

void MessageHandler::writeMessage() const
{
    MessageWriter messageWriter( player_, plug_, messagesData_.messages()[indexMessage_] );

    messageWriter.writeMessage();
}

void MessageHandler::nextMessage() const
{
    indexMessage_++;

    writeMessage();
}

void MessageHandler::setIndexMessage( const int& indexMessage ) const
{
    indexMessage_ = indexMessage;
}