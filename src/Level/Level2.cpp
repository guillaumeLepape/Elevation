/*!
    * \file Level2.cpp
*/


#include "Level2.h"

#include <memory>

#include "../Action/Negociate.h"

#include "../Writer/Writer.h"

void Level2::startLevel()
{
    Plug plug( "Jean-Luc Delarue", 80 );

    HeaderData headerData(levelNumber_);
    HeaderWriter headerWriter(headerData);

    headerWriter.writeHeader();

    Message message( "../messages/messageLevel2.json" );
    // message.writeHeader();

    MessagesData messagesData(levelNumber_);
    MessagesWriter messagesWriter(player_, &plug, messagesData);

    messagesWriter.nextMessage();
    // message.writeInConsole( player_, &plug, 0 );

    Negociate negociate( player_, &plug, message );
    negociate.triggerAction();
    
    std::cout << "\n";
}