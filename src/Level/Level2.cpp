/*!
    * \file Level2.cpp
*/


#include "Level2.h"

#include "Negociate.h"

#include "HeaderWriter.h"

void Level2::startLevel( const Options& options )
{
    Plug plug( "Jean-Luc Delarue", 80 );

    HeaderWriter headerWriter( 
        data::Level2::nameLevel,
        data::Level2::hour,
        data::Level2::minut
    );
    headerWriter.writeHeader();

    auto message = data::Level2::message0( plug.name(), plug.price() );
    MessageWriter messageWriter
    ( 
        message,
        player_->pseudo(),
        plug.name()
    );
    messageWriter.writeMessage();

    Negociate negociate( player_, &plug, data::Action::statementNegociate, data::Action::resultNegociate );
    negociate.triggerAction();
    
    Level::endOfLevel();

    std::cout << "\n";
}