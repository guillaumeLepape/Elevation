/*!
    * \file Level1.cpp
*/

#include "Level1.h"

#include <memory>

#include "../Plug/Plug.h"

#include <iostream>

#include "../Writer/Writer.h"

void Level1::startLevel()
{
    Plug plug( "Petite frappe", 20);

    HeaderData headerData(levelNumber_);
    HeaderWriter headerWriter(headerData);

    headerWriter.writeHeader();

    MessagesData messagesData(levelNumber_);
    MessagesWriter messagesWriter(player_, &plug, messagesData);

    messagesWriter.nextMessage();

    // Message message( "../messages/messageLevel1.json" );
    // message.writeHeader();
    // message.writeInConsole( player_, &plug, 0 );

    player_->increaseMoney( -plug.price() );

    std::cout << "\n";
}