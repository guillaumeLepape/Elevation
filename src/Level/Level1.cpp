/*!
    * \file Level1.cpp
*/

#include "Level1.h"

#include <memory>
#include <iostream>

#include "HeaderWriter.h"
#include "MessageHandler.h"

void Level1::startLevel()
{
    std::string folder = "data/Level1";

    Plug plug( "Petite frappe", 20);

    HeaderWriter headerWriter( folder, "header" );
    headerWriter.writeHeader();

    MessageHandler messageHandler( player_, &plug, folder, "message" );
    messageHandler.nextMessage();

    player_->increaseMoney( -plug.price() );

    std::cout << "\n";
}