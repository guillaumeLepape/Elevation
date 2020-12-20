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
#include "../Selection/Fight.h"

void Level5::startLevel()
{
    std::string folder = "data/Level5";

    HeaderWriter headerWriter( folder, "header" );
    headerWriter.writeHeader();

    Plug guetteur( "Guetteur", 0, 15 );

    MessageHandler messageHandler( player_, &guetteur, folder, "message" );
    messageHandler.nextMessage();

    /**********************/
    player_->addWeapon( Weapon("knife", 30, "Plantez !") );
    /**********************/

    UseWeapon beatUp( player_, &guetteur, "fist", "data/Weapon", "beatUp" );
    UseWeapon cutThroat( player_, &guetteur, "knife", "data/Weapon", "cutThroat" );

    Selection::select(
        { &beatUp, &cutThroat },
        folder,
        "selection0"
    );

    Plug randomDebile( "Random débile", 0, 50 );
    Plug randomDebile2( "Random débile 2", 0, 70 );
    Plug pasFuteFute( "Pas fute-fute", 0, 100 );

    std::vector<Plug> enemies;
    enemies.push_back( randomDebile );
    enemies.push_back( randomDebile2 );
    enemies.push_back( pasFuteFute );


    Fight fight( 
        player_, 
        enemies,
        messageHandler 
    );
    fight.startFight(); 

    std::cout << "\n";
}