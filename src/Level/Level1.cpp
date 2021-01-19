/*!
    * \file Level1.cpp
*/

#include "Level1.h"

#include "HeaderWriter.h"
#include "MessageHandler.h"

void Level1::startLevel( const Options& options )
{
    Plug plug( "Petite frappe", 20);

    HeaderWriter headerWriter( 
        data::Level1::nameLevel,
        data::Level1::hour,
        data::Level1::minut
    );
    headerWriter.writeHeader();

    MessageHandler messageHandler( data::Level1::messages );
    messageHandler.preTreatment( player_, &plug );
    messageHandler.nextMessage();

    player_->increaseMoney( -plug.price() );

    Level::endOfLevel();

    std::cout << "\n";
}