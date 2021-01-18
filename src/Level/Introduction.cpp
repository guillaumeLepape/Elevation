/*!
    * \file Introduction.cpp
*/

#include "Introduction.h"

void Introduction::startLevel( const Options& options )
{
    HeaderWriter headerWriter
    ( 
        data::Introduction::nameLevel,
        data::Introduction::hour,
        data::Introduction::minut
    );
    headerWriter.writeHeader();

    MessageHandler messageHandler( data::Introduction::messages );
    messageHandler.preTreatmentNextMessage( player_, nullptr );
    messageHandler.nextMessage();

    Pseudo pseudo( player_, messageHandler, data::Action::statementPseudo, data::Action::resultPseudo );
    pseudo.triggerAction();

    messageHandler.preTreatment( player_, nullptr, 4 );
    messageHandler.writeMessage(4);

    Level::endOfLevel();

    std::cout << "\n";
}