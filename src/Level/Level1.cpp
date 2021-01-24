/*!
    * \file Level1.cpp
*/

#include "Level1.h"

#include <iostream>

#include "HeaderWriter.h"
#include "MessageWriter.h"

#include "Languages.h"

#include "Plug.h"

void Level1::startLevel( const Options& options )
{
    Plug plug( "Petite frappe", 20);

    HeaderWriter headerWriter( 
        data::Level1::nameLevel,
        data::Level1::hour,
        data::Level1::minut
    );
    headerWriter.writeHeader();

    auto message = data::Level1::message0( player_->pseudo(), plug.name(), plug.price() );

    MessageWriter messageWriter( message, player_->pseudo(), plug.name() );
    messageWriter.writeMessage();

    player_->increaseMoney( -plug.price() );

    Level::endOfLevel();

    std::cout << "\n";
}