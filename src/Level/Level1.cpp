/*!
    * \file Level1.cpp
*/

#include "Level1.h"

#include <memory>
#include <iostream>

#include "../Writer/HeaderWriter.h"
#include "../Writer/MessageHandler.h"

void Level1::startLevel()
{
    Plug plug( "Petite frappe", 20);

    HeaderWriter headerWriter( levelNumber_ );
    headerWriter.writeHeader();

    MessageHandler messageHandler( levelNumber_, player_, &plug );
    messageHandler.nextMessage();

    player_->increaseMoney( -plug.price() );

    std::cout << "\n";
}