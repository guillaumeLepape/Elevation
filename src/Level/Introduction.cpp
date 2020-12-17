/*!
    * \file Introduction.cpp
*/

#include "Introduction.h"

#include "../Writer/Writer.h"
#include "../Action/Pseudo.h"

void Introduction::startLevel()
{
    HeaderWriter headerWriter( levelNumber_ );
    headerWriter.writeHeader();

    MessageHandler messageHandler( levelNumber_, player_, nullptr );
    messageHandler.nextMessage();

    Pseudo pseudo( player_ );
    pseudo.triggerAction();

    messageHandler.nextMessage();

    std::cout << "\n";
}