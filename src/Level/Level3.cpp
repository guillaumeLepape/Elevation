/*!
    * \file Level3.cpp
*/

#include "Level3.h"

#include "Selection.h"
#include "UseWeapon.h"
#include "Knife.h"
#include "Fist.h"

#include "HeaderWriter.h"
#include "MessageHandler.h"

void Level3::startLevel( const Options& options )
{
    std::string folder = "data/Level3";

    Plug plug( "V", 20 );

    HeaderWriter headerWriter( 
        data::Level3::nameLevel,
        data::Level3::hour,
        data::Level3::minut
    );
    headerWriter.writeHeader();

    MessageHandler messageHandler( folder, "message" );
    messageHandler.preTreatment( player_, &plug );
    messageHandler.nextMessage();
    
    UseWeapon useFist( player_, &plug, Fist(), data::Action::statementUseFist, data::Action::resultUseWeapon );

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

    player_->addWeapon( Knife() );

    UseWeapon useKnife( player_, &plug, Knife(), data::Action::statementUseKnife, data::Action::resultUseWeapon );

    Selection::select(
        { &useFist, &useKnife },
        folder,
        "selection3"
    );

    Level::endOfLevel();

    std::cout << "\n";
}
