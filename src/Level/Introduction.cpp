/*!
    * \file Introduction.cpp
*/

#include "Introduction.h"

#include "HeaderWriter.h"
#include "Pseudo.h"

void Introduction::startLevel()
{
    std::string folder = "data/Introduction";

    HeaderWriter headerWriter( folder, "header" );
    headerWriter.writeHeader();

    MessageHandler messageHandler( player_, nullptr, folder, "message" );
    messageHandler.nextMessage();

    Pseudo pseudo( player_, messageHandler, folder, "pseudo" );
    pseudo.triggerAction();

    messageHandler.writeMessage(2);

    std::cout << "\n";
}