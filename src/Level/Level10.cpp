/*!
    * \file Level10.cpp
*/

#include "Level10.h"

#include <iostream>

#include "HeaderWriter.h"
#include "MessageWriter.h"

#include "Plug.h"
#include "Fight.h"

#include "IncreaseMaxLifePoints.h"

#include "DivineStrike.h"

#include "Languages.h"

void Level10::startLevel()
{
    HeaderWriter headerWriter( data::Level10::nameLevel, data::Level10::hour, data::Level10::minut );
    headerWriter.writeHeader();

    const DivineStrike* divineStrike = new DivineStrike();
    Plug plug( "Dieu", 10000000, divineStrike );

    std::vector<MessageWriter> messageWriters;
    messageWriters.push_back( MessageWriter( data::Level10::message0, player_->name(), plug.name() ) );
    messageWriters.push_back( MessageWriter( data::Level10::message1, player_->name(), plug.name() ) );

    Fight fight( player_, { &plug }, {}, options_.noRule_ );
    fight.startFight( 
        messageWriters,
        [&divineStrike](Player* const player_) -> bool { return player_->nbLifePoints() < divineStrike->damageWeapon(); } 
    );

    Level::endOfLevel();
    std::cout << "\n";
}