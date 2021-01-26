/*!
    * \file Level3.cpp
*/

#include "Level3.h"

#include <iostream>

#include "Selection.h"
#include "UseWeapon.h"
#include "Knife.h"
#include "Fist.h"

#include "HeaderWriter.h"
#include "MessageWriter.h"

#include "Languages.h"

void Level3::startLevel()
{
    Plug plug( "V", 100 );

    HeaderWriter headerWriter( 
        data::Level3::nameLevel,
        data::Level3::hour,
        data::Level3::minut
    );
    headerWriter.writeHeader();

    MessageWriter messageWriter0( data::Level3::message0, player_->name(), plug.name() );
    messageWriter0.writeMessage();

    const Fist fist;
    UseWeapon useFist( player_, &plug, fist, data::Action::statementUseFist, data::Action::resultUseWeapon( plug.name(), fist.damageWeapon() ) );
    useFist.triggerAction();

    MessageWriter messageWriter1( data::Level3::message1, player_->name(), plug.name() );
    messageWriter1.writeMessage();

    Selection::select(
        { &useFist },
        data::Action::titleChooseWeapon
    );

    auto message = data::Level3::message2( plug.name() );
    MessageWriter messageWriter2( message, player_->name(), plug.name() );
    messageWriter2.writeMessage();

    Selection::select(
        { &useFist },
        data::Action::titleChooseWeapon
    );

    MessageWriter messageWriter3( data::Level3::message3, player_->name(), plug.name() );
    messageWriter3.writeMessage();

    Selection::select(
        { &useFist },
        data::Action::titleChooseWeapon
    );

    MessageWriter messageWriter4( data::Level3::message4, player_->name(), plug.name() );
    messageWriter4.writeMessage();

    const Knife* knife = new Knife();
    player_->weapons()->addWeapon( knife );

    UseWeapon useKnife( player_, &plug, *knife, data::Action::statementUseKnife, data::Action::resultUseWeapon(plug.name(), knife->damageWeapon()) );

    Selection::select(
        { &useFist, &useKnife },
        data::Action::titleChooseWeapon
    );

    Level::endOfLevel();

    std::cout << "\n";
}
