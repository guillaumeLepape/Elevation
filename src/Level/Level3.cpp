/*!
    * \file Level3.cpp
*/

#include "Level3.h"

#include "Selection.h"
#include "UseWeapon.h"
#include "Knife.h"
#include "Fist.h"

#include "HeaderWriter.h"
#include "MessageWriter.h"

void Level3::startLevel( const Options& options )
{
    Plug plug( "V", 20 );

    HeaderWriter headerWriter( 
        data::Level3::nameLevel,
        data::Level3::hour,
        data::Level3::minut
    );
    headerWriter.writeHeader();

    MessageWriter messageWriter0( data::Level3::message0, player_->pseudo(), plug.name() );
    messageWriter0.writeMessage();

    UseWeapon useFist( player_, &plug, Fist(), data::Action::statementUseFist, data::Action::resultUseWeapon );
    useFist.triggerAction();

    MessageWriter messageWriter1( data::Level3::message1, player_->pseudo(), plug.name() );
    messageWriter1.writeMessage();

    Selection::select(
        { &useFist },
        data::Action::titleChooseWeapon
    );

    auto message = data::Level3::message2( plug.name() );
    MessageWriter messageWriter2( message, player_->pseudo(), plug.name() );
    messageWriter2.writeMessage();

    Selection::select(
        { &useFist },
        data::Action::titleChooseWeapon
    );

    MessageWriter messageWriter3( data::Level3::message3, player_->pseudo(), plug.name() );
    messageWriter3.writeMessage();

    Selection::select(
        { &useFist },
        data::Action::titleChooseWeapon
    );

    MessageWriter messageWriter4( data::Level3::message4, player_->pseudo(), plug.name() );
    messageWriter4.writeMessage();

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
