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
        data::Action::titleChooseWeapon
    );

    messageHandler.writeMessage(2);

    Selection::select(
        { &useFist },
        data::Action::titleChooseWeapon
    );

    messageHandler.nextMessage();

    Selection::select(
        { &useFist },
        data::Action::titleChooseWeapon
    );

    messageHandler.nextMessage();

    Knife knife;
    player_->addWeapon( knife );

    UseWeapon useKnife( player_, &plug, knife, data::Action::statementUseKnife, data::Action::resultUseWeapon );

    Selection::select(
        { &useFist, &useKnife },
        data::Action::titleChooseWeapon
    );

    Level::endOfLevel();

    std::cout << "\n";
}
