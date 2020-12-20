/*!
    * \file MessageHandler.cpp
*/

#include "MessageHandler.h"

MessageHandler::MessageHandler
( 
    const Player* const player, 
    const Plug* const plug, 
    const nlohmann::json& jsonObject,
    int indexMessage
) :
    player_( player ),
    plug_( plug ),
    messagesData_( jsonObject ),
    indexMessage_( indexMessage )
{

}

MessageHandler::MessageHandler
(
    const Player* const player, 
    const Plug* const plug, 
    const MessagesData& messagesData,
    int indexMessage
) :
    player_( player ),
    plug_( plug ),
    messagesData_( messagesData ),
    indexMessage_( indexMessage )
{

}

MessageHandler::MessageHandler
(
    const Player* const player, 
    const Plug* const plug, 
    const std::string& folderFromRoot,
    const std::string& nameFile,
    int indexMessage
) :
    player_( player ),
    plug_( plug ),
    messagesData_( folderFromRoot, nameFile ),
    indexMessage_( indexMessage )
{

}

void MessageHandler::writeMessagePrivate() const
{
    MessageWriter messageWriter( player_, plug_, messagesData_.messages()[indexMessage_] );
    messageWriter.writeMessage();
}

void MessageHandler::writeMessage( const int& indexMessage ) const 
{
    indexMessage_ = indexMessage;

    writeMessagePrivate();
}

void MessageHandler::nextMessage() const
{
    indexMessage_++;

    writeMessagePrivate();
}