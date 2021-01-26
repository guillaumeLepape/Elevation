/*!
    * \file Level2.cpp
*/


#include "Level2.h"

#include <iostream>

#include "HeaderWriter.h"
#include "MessageWriter.h"

#include "Negociate.h"

#include "Plug.h"

#include "Languages.h"

void Level2::startLevel( const Options& options )
{
    Plug plug( "Jean-Luc Delarue" );

    HeaderWriter headerWriter( 
        data::Level2::nameLevel,
        data::Level2::hour,
        data::Level2::minut
    );
    headerWriter.writeHeader();

    int price = 80;
    auto message = data::Level2::message0( plug.name(), price );
    MessageWriter messageWriter
    ( 
        message,
        player_->name(),
        plug.name()
    );
    messageWriter.writeMessage();

    Negociate negociate
    ( 
        player_, 
        &plug, 
        price, 
        data::Action::statementNegociate, 
        data::Action::resultNegociate(0) 
    );
    negociate.triggerAction();
    
    Level::endOfLevel();

    std::cout << "\n";
}