/*!
    * \file Level1.cpp
*/

#include "Level1.h"

#include <memory>
#include <iostream>

#include "../Plug/Plug.h"
#include "../Writer/Writer.h"

void Level1::startLevel()
{
    Plug plug( "Petite frappe", 20);

    HeaderWriter headerWriter( levelNumber_ );
    headerWriter.writeHeader();

    MessagesWriter messagesWriter( levelNumber_, player_, &plug );
    messagesWriter.nextMessage();

    player_->increaseMoney( -plug.price() );

    std::cout << "\n";
}