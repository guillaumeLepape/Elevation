/*!
    * \file MessagesWriter.cpp
*/

#include "MessagesWriter.h"

MessagesWriter::MessagesWriter
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

void MessagesWriter::writeMessage() const
{
    MessageWriter messageWriter( player_, plug_, messagesData_.messages()[indexMessage_] );

    messageWriter.writeMessage();
}

void MessagesWriter::nextMessage()
{
    indexMessage_++;

    writeMessage();
}

void MessagesWriter::setIndexMessage( const int& indexMessage )
{
    indexMessage_ = indexMessage;
}