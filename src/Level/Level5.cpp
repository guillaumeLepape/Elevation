/*!
    * \file Level5.cpp
*/

#include "Level5.h"

#include "HeaderWriter.h"

#include "UseWeapon.h"
#include "Selection.h"
#include "Fight.h"

void Level5::startLevel()
{
    std::string folder = "data/Level5";

    HeaderWriter headerWriter( folder, "header" );
    headerWriter.writeHeader();

    Plug guetteur( "Guetteur", 0, 15 );

    MessageHandler messageHandler( folder, "message" );
    messageHandler.preTreatment( player_, &guetteur );
    messageHandler.nextMessage();

    UseWeapon beatUp( player_, &guetteur, "fist", "data/Weapon", "beatUp" );
    UseWeapon cutThroat( player_, &guetteur, "knife", "data/Weapon", "cutThroat" );

    Selection::select(
        { &beatUp, &cutThroat },
        folder,
        "selection0"
    );

    Plug randomDebile( "Random debile", 0, 50 );
    Plug randomDebile2( "Random debile 2", 0, 70 );
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