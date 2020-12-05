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
    
    std::unique_ptr<Action> hit( new Hit(player_, plug) );

    hit->triggerAction();

    message.writeInConsole( player_, plug, 1 );

    // first selection menu
    Selection selection;

    selection.select(
        "Choix",
        { hit.get() } 
    );

    message.writeInConsole( player_, plug, 2 );

    selection.select(
        "Choix",
        { hit.get() }
    );

    message.writeInConsole( player_, plug, 3 );

    selection.select(
        "Choix",
        { hit.get() }
    );

    message.writeInConsole( player_, plug, 4 );

    delete plug;

    std::cout << "\n";
}
