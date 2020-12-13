/*!
    * \file Level1.cpp
*/

#include "Level1.h"

#include <memory>

#include "../Plug/Plug.h"
#include "../Message/Message.h"

void Level1::startLevel()
{
    Plug plug( "Petite frappe", 20);

    Message message( "../messages/messageLevel1.json" );
    message.writeHeader();
    message.writeInConsole( player_, &plug, 0 );

    player_->increaseMoney( -plug.price() );

    std::cout << "\n";
}