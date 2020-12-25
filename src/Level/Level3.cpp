/*!
    * \file Level3.cpp
*/

#include "Level3.h"

#include "Selection.h"
#include "UseWeapon.h"

#include "HeaderWriter.h"
#include "MessageHandler.h"

void Level3::startLevel()
{
    std::string folder = "data/Level3";

    Plug plug( "V", 20 );

    HeaderWriter headerWriter( folder, "header" );
    headerWriter.writeHeader();

    MessageHandler messageHandler( folder, "message" );
    messageHandler.preTreatment( player_, &plug );
    messageHandler.nextMessage();
    
    UseWeapon useFist( player_, &plug, "fist", "data/Weapon", "useFist" );

    useFist.triggerAction();

    messageHandler.nextMessage();

    Selection::select(
        { &useFist },
        folder,
        "selection0" 
    );

    messageHandler.writeMessage(2);

    Selection::select(
        { &useFist },
        folder,
        "selection1"
    );

    messageHandler.nextMessage();

    Selection::select(
        { &useFist },
        folder,
        "selection2"
    );

    messageHandler.nextMessage();

    player_->addWeapon( Weapon( "knife", 30, "Plantez !" ) );

    UseWeapon useKnife( player_, &plug, "knife", "data/Weapon", "useKnife" );

    Selection::select(
        { &useFist, &useKnife },
        folder,
        "selection3"
    );

    std::cout << "\n";
}
