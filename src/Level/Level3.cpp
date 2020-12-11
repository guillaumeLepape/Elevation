/*!
    * \file Level3.cpp
*/

#include "Level3.h"

#include "../Plug/Plug.h"
#include "../Selection/Selection.h"
#include "../Action/UseWeapon.h"

void Level3::startLevel()
{
    Plug* plug = new Plug( "V", 20 );

    Message message( "../messages/messageLevel3.json" );
    message.writeHeader();

    message.writeInConsole( player_, plug, 0 );
    
    UseWeapon useFist( player_, plug, "fist" );

    useFist.triggerAction();

    message.writeInConsole( player_, plug, 1 );

    Selection::select(
        "Choix de l'arme",
        { &useFist } 
    );

    message.writeInConsole( player_, plug, 2 );

    Selection::select(
        "Choix de l'arme",
        { &useFist }
    );

    message.writeInConsole( player_, plug, 3 );

    Selection::select(
        "Choix de l'arme",
        { &useFist }
    );

    message.writeInConsole( player_, plug, 4 );

    player_->addWeapon( Weapon( "knife", 30, "Plantez !" ) );

    UseWeapon useKnife( player_, plug, "knife" );

    Selection::select(
        "Choix de l'arme",
        { &useFist, &useKnife }
    );

    delete plug;

    std::cout << "\n";
}
