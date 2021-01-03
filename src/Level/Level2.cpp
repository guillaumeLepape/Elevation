/*!
    * \file Level2.cpp
*/


#include "Level2.h"

#include <memory>

#include "Negociate.h"

#include "HeaderWriter.h"

void Level2::startLevel( const Options& options )
{
    std::string folder = "data/Level2";

    Plug plug( "Jean-Luc Delarue", 80 );

    HeaderWriter headerWriter( folder, "header" );
    headerWriter.writeHeader();

    MessageHandler messageHandler( folder, "message" );
    messageHandler.preTreatment( player_, &plug );
    messageHandler.nextMessage();

    Negociate negociate( player_, &plug, messageHandler, folder, "negociate" );
    negociate.triggerAction();
    
    std::cout << "\n";
}