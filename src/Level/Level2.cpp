/*!
    * \file Level2.cpp
*/


#include "Level2.h"

#include <memory>

#include "../Action/Negociate.h"

#include "../Writer/Writer.h"

void Level2::startLevel()
{
    Plug plug( "Jean-Luc Delarue", 80 );

    HeaderWriter headerWriter( levelNumber_ );
    headerWriter.writeHeader();

    MessagesWriter messagesWriter( levelNumber_, player_, &plug );

    messagesWriter.nextMessage();

    Negociate negociate( player_, &plug, messagesWriter );
    negociate.triggerAction();
    
    std::cout << "\n";
}