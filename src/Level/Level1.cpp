/*!
    * \file Level1.cpp
*/

#include "Level1.h"

#include "HeaderWriter.h"
#include "MessageHandler.h"

void Level1::startLevel( const Options& options )
{
    std::string folder = "data/Level1";

    Plug plug( "Petite frappe", 20);

    HeaderWriter headerWriter( folder, "header" );
    headerWriter.writeHeader();

    MessageHandler messageHandler( folder, "message" );
    messageHandler.preTreatment( player_, &plug );
    messageHandler.nextMessage();

    player_->increaseMoney( -plug.price() );

    Level::endOfLevel();

    std::cout << "\n";
}