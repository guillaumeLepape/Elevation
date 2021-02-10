/*!
    * \file Level10.cpp
*/

#include "Level10.h"

#include <iostream>

#include "HeaderWriter.h"
#include "MessageWriter.h"

#include "Plug.h"
#include "Fight.h"
#include "PlugAttack.h"
#include "AddWeaponAction.h"

#include "IncreaseMaxLifePoints.h"

#include "Heroine.h"
#include "DivineStrike.h"
#include "AK47.h"

#include "Languages.h"

void Level10::startLevel()
{
    HeaderWriter headerWriter( data::Level10::nameLevel, data::Level10::hour, data::Level10::minut );
    headerWriter.writeHeader();

    const DivineStrike* divineStrike = new DivineStrike();
    Plug plug( "Dieu", 10000000, divineStrike );

    MessageWriter messageWriterMinus1( data::Level10::messageMinus1, player_->name(), plug.name() );
    messageWriterMinus1.writeMessage();

    const AK47* ak47 = new AK47(100);
    AddWeaponAction addWeaponAction
    ( 
        player_, 
        ak47, 
        "", 
        data::Action::resultAddWeapon(ak47->name()) 
    );
    addWeaponAction.triggerAction(); 

    std::vector<MessageWriter> messageWriters;
    messageWriters.push_back( MessageWriter( data::Level10::message0, player_->name(), plug.name() ) );
    messageWriters.push_back( MessageWriter( data::Level10::message1, player_->name(), plug.name() ) );

    Fight fight( player_, { &plug }, {}, options_.noRule_ );
    fight.startFight( 
        messageWriters,
        [&divineStrike](Player* const player_) -> bool { return player_->nbLifePoints() < divineStrike->damageWeapon(); } 
    );

    MessageWriter messageWriter0( data::Level10::message2, player_->name(), plug.name() );
    messageWriter0.writeMessage();

    Plug heroine( "Heroine", 100, new Heroine() );
    PlugAttack plugAttack
    ( 
        player_, 
        &heroine,
        "",
        ""
    );

    MessageWriter messageWriter1( data::Level10::message3, player_->name(), "" );

    while ( !(player_->dead()) )
    {
        plugAttack.triggerAction();
        messageWriter1.writeMessage();
    }

    MessageWriter messageWriter2( data::Level10::message4, player_->name(), plug.name() );
    messageWriter2.writeMessage();

    Level::endOfLevel();
    std::cout << "\n";
}