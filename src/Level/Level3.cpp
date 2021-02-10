/*!
    * \file Level3.cpp
*/

#include "Level3.h"

#include <iostream>

#include "Selection.h"
#include "UseWeapon.h"
#include "AddWeaponAction.h"
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

    const std::unique_ptr<Fist> fist( new Fist() );
    std::unique_ptr<UseWeapon> useFist( new UseWeapon( player_, &plug, fist.get(), data::Weapon::resultUseWeapon( plug.name(), fist->damageWeapon() ) ) );
    useFist->triggerAction();

    MessageWriter messageWriter1( data::Level3::message1, player_->name(), plug.name() );
    messageWriter1.writeMessage();

    Selection::select(
        { useFist.get() },
        data::Action::titleChooseWeapon
    );

    auto message = data::Level3::message2( plug.name() );
    MessageWriter messageWriter2( message, player_->name(), plug.name() );
    messageWriter2.writeMessage();

    Selection::select(
        { useFist.get() },
        data::Action::titleChooseWeapon
    );

    MessageWriter messageWriter3( data::Level3::message3, player_->name(), plug.name() );
    messageWriter3.writeMessage();

    Selection::select(
        { useFist.get() },
        data::Action::titleChooseWeapon
    );

    MessageWriter messageWriter4( data::Level3::message4, player_->name(), plug.name() );
    messageWriter4.writeMessage();

    const Knife* knife = new Knife();
    AddWeaponAction addWeaponAction
    ( 
        player_, 
        knife, 
        "", 
        data::Action::resultAddWeapon(knife->name()) 
    );
    addWeaponAction.triggerAction();

    std::unique_ptr<UseWeapon> useKnife( new UseWeapon( player_, &plug, knife, data::Weapon::resultUseWeapon(plug.name(), knife->damageWeapon()) ) );

    Selection::select(
        { useFist.get(), useKnife.get() },
        data::Action::titleChooseWeapon
    );

    MessageWriter messageWriter5( data::Level3::message5, player_->name(), plug.name() );
    messageWriter5.writeMessage();

    Level::endOfLevel();

    std::cout << "\n";
}
