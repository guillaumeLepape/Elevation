/*!
    * \file Level3.cpp
*/

#include "Level3.h"

void Level3::startLevel( const Options& options )
{
    Plug plug( "V", 20 );

    HeaderWriter headerWriter( 
        data::Level3::nameLevel,
        data::Level3::hour,
        data::Level3::minut
    );
    headerWriter.writeHeader();

    MessageHandler messageHandler( data::Level3::messages );
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
