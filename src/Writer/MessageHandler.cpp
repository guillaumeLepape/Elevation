/*!
    * \file MessageHandler.cpp
*/

#include "MessageHandler.h"

MessageHandler::MessageHandler
( 
    const nlohmann::json& jsonObject,
    int indexMessage
) :
    messagesData_( jsonObject ),
    indexMessage_( indexMessage )
{

}

MessageHandler::MessageHandler
(
    const std::vector<std::vector<std::tuple<std::string, bool, std::string>>>& messages,
    int indexMessage
) :
    messagesData_( messages ),
    indexMessage_( indexMessage )
{

}

MessageHandler::MessageHandler
(
    const MessagesData& messagesData,
    int indexMessage
) :
    messagesData_( messagesData ),
    indexMessage_( indexMessage )
{

}

MessageHandler::MessageHandler
(
    const std::string& folderFromRoot,
    const std::string& nameFile,
    int indexMessage
) :
    messagesData_( folderFromRoot, nameFile ),
    indexMessage_( indexMessage )
{

}

void MessageHandler::writeMessagePrivate() const
{
    MessageWriter messageWriter( messagesData_.messages()[indexMessage_] );
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