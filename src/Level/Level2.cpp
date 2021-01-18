/*!
    * \file Level2.cpp
*/


#include "Level2.h"

void Level2::startLevel( const Options& options )
{
    Plug plug( "Jean-Luc Delarue", 80 );

    HeaderWriter headerWriter( 
        data::Level2::nameLevel,
        data::Level2::hour,
        data::Level2::minut
    );
    headerWriter.writeHeader();

    MessageHandler messageHandler( data::Level2::messages );
    messageHandler.preTreatment( player_, &plug );
    messageHandler.nextMessage();

    Negociate negociate( player_, &plug, messageHandler, data::Action::statementNegociate, data::Action::resultNegociate );
    negociate.triggerAction();
    
    Level::endOfLevel();

    std::cout << "\n";
}