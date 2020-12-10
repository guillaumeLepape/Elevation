/*!
    * \file Level2.cpp
*/


#include "Level2.h"

#include <memory>

#include "../Action/Negociate.h"

void Level2::startLevel()
{
    Plug* plug = new Plug("Jean-Luc Delarue", 80);

    Message message( "../messages/messageLevel2.json" );
    message.writeHeader();

    message.writeInConsole( player_, plug, 0 );

    Negociate negociate( player_, plug, message );
    negociate.triggerAction();
    
    delete plug;

    std::cout << "\n";
}