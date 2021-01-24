/*!
    * \file Introduction.cpp
*/

#include "Introduction.h"

#include <iostream>

#include "HeaderWriter.h"
#include "MessageWriter.h"
#include "Pseudo.h"

#include "Languages.h"

void Introduction::startLevel( const Options& options )
{
    HeaderWriter headerWriter
    ( 
        data::Introduction::nameLevel,
        data::Introduction::hour,
        data::Introduction::minut
    );
    headerWriter.writeHeader();

    MessageWriter messageWriter0
    ( 
        data::Introduction::message0, 
        player_->pseudo(), 
        "" 
    );
    messageWriter0.writeMessage();

    Pseudo pseudo( player_, data::Action::statementPseudo, data::Action::resultPseudo(player_->pseudo()) );
    pseudo.triggerAction();

    MessageWriter messageWriter4
    ( 
        data::Introduction::message4( player_->pseudo() ), 
        player_->pseudo(), 
        "" 
    );
    messageWriter4.writeMessage();

    Level::endOfLevel();

    std::cout << "\n";
}