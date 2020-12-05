/*!
    * \file Level3.cpp
*/

#include "Level3.h"

#include "../Plug/Plug.h"
#include "../Message/Message.h"
#include "../Selection/Selection.h"
#include "../Action/Hit.h"

void Level3::startLevel()
{
    Plug* plug = new Plug( "V", 20 );

    Message message( "../messages/messageLevel3.json" );
    message.writeHeader();

    message.writeInConsole( player_, plug, 0 );
    
    // first selection menu
    Selection selection;

    std::unique_ptr<Action> hit( new Hit(player_, plug) );

    selection.select(
        { hit.get() } 
    );

    message.writeInConsole( player_, plug, 1 );

    selection.select(
        { hit.get() } 
    );

    message.writeInConsole( player_, plug, 2 );

    selection.select(
        { hit.get() }
    );

    message.writeInConsole( player_, plug, 3 );

    delete plug;

    std::cout << "\n";
}
