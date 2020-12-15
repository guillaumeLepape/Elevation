/*!
    * \file Introduction.cpp
*/

#include "Introduction.h"

#include "../Action/Pseudo.h"

#include "../Writer/Writer.h"

void Introduction::startLevel()
{
    HeaderData headerData( levelNumber_ );
    HeaderWriter headerWriter( headerData );

    headerWriter.writeHeader();

    MessagesData messagesData( levelNumber_ );
    MessagesWriter messagesWriter( player_, nullptr, messagesData );

    messagesWriter.nextMessage();

    Pseudo pseudo( player_ );
    pseudo.triggerAction();

    messagesWriter.nextMessage();

    std::cout << "\n";
}