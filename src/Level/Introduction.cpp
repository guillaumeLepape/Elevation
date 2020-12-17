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

    MessagesWriter messagesWriter( levelNumber_, player_, nullptr );
    messagesWriter.nextMessage();

    Pseudo pseudo( player_ );
    pseudo.triggerAction();

    messagesWriter.nextMessage();

    std::cout << "\n";
}