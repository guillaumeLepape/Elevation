/*!
    * \file Level7.cpp
*/

#include "Level7.h"

#include <iostream>

#include "HeaderWriter.h"
#include "MessageWriter.h"

#include "Plug.h"

#include "Ninemm.h"

#include "Languages.h"

void Level7::startLevel( const Options& options )
{
    Plug plug( "Mathilde", 0, 30 );

    HeaderWriter headerWriter( data::Level7::nameLevel, data::Level7::hour, data::Level7::minut );
    headerWriter.writeHeader();

    MessageWriter messageWriter
    ( 
        data::Level7::message0( plug.name() ), 
        player_->name(),  
        plug.name()
    );
    messageWriter.writeMessage();

    player_->addWeapon( new Ninemm(3) );

    Level::endOfLevel();

    std::cout << "\n";
}