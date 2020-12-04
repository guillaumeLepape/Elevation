/*!
    * \file Level3.cpp
*/

#include "Level3.h"

#include "../Plug/Plug.h"
#include "../Message/Message.h"
#include "../Selection/Selection.h"

void Level3::startLevel()
{
    Plug* plug = new Plug( "V", 20 );

    Message message( "../messages/messageLevel3.json" );
    message.writeHeader();

    message.writeInConsole( player_, plug, 0 );
    
    Selection firstSelection;

    // selectBeginGame.select(
    //     { startGame.get(), quit.get() } 
    // );


    std::cout << "\n";
}
