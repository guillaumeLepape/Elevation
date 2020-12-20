/*!
    * \file Level5.cpp
*/

#include "Level5.h"

#include <iostream>

#include "../Plug/Plug.h"
#include "../Writer/HeaderWriter.h"
#include "../Writer/MessageHandler.h"

#include "../Action/UseWeapon.h"
#include "../Selection/Selection.h"

void Level5::startLevel()
{
    // Plug plug( "Future", 100 );

    HeaderWriter headerWriter( levelNumber_ );
    headerWriter.writeHeader();

    Plug guetteur( "Guetteur", 30 );

    MessageHandler messageHandler( levelNumber_, player_, &guetteur );
    messageHandler.nextMessage();

    UseWeapon cutThroat( levelNumber_, "cutThroat", player_, &guetteur, "knife" );

    Selection::select(
        levelNumber_,
        0,
        { &cutThroat }
    );

    Plug randomDebile( "Random débile", 50 );
    Plug randomDebile2( "Random débile 2", 70 );
    Plug pasFuteFute( "Pas fute-fute", 100 );



    std::cout << "\n";
}