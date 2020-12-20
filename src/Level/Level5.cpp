/*!
    * \file Level5.cpp
*/

#include "Level5.h"

#include <iostream>

#include "../Plug/Plug.h"
#include "../Writer/HeaderWriter.h"
#include "../Writer/MessageHandler.h"

void Level5::startLevel()
{
    Plug plug( "Future", 100 );

    HeaderWriter headerWriter( levelNumber_ );
    headerWriter.writeHeader();

    MessageHandler messageHandler( levelNumber_, player_, &plug );
    messageHandler.nextMessage();

    std::cout << "\n";
}