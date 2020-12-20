/*!
    * \file Introduction.cpp
*/

#include "Introduction.h"

#include "../Writer/HeaderWriter.h"
#include "../Writer/MessageHandler.h"
#include "../Action/Pseudo.h"

void Introduction::startLevel()
{
    std::string folder = "data/Introduction";

    HeaderWriter headerWriter( folder, "header" );
    headerWriter.writeHeader();

    MessageHandler messageHandler( player_, nullptr, folder, "message" );
    messageHandler.nextMessage();

    Pseudo pseudo( player_, folder, "pseudo" );
    pseudo.triggerAction();

    messageHandler.nextMessage();

    std::cout << "\n";
}