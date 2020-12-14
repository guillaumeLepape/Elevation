/*!
    * \file Level5.cpp
*/

#include "Level5.h"

#include "../Plug/Plug.h"
#include "../Message/Message.h"

void Level5::startLevel()
{
    Plug plug( "Future", 100 );

    Message message( "../messages/messageLevel5.json" );

    message.writeHeader();

    std::cout << "\n";
}