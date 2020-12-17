/*!
    * \file Level3.cpp
*/

#include "Level3.h"

#include <iostream>

#include "../Selection/Selection.h"
#include "../Action/UseWeapon.h"

#include "../Writer/Writer.h"

void Level3::startLevel()
{
    Plug plug( "V", 20 );

    HeaderWriter headerWriter( levelNumber_ );
    headerWriter.writeHeader();

    // MessagesData messageData( levelNumber_ );
    MessageHandler messageHandler( levelNumber_, player_, &plug );
    messageHandler.nextMessage();
    // Message message( "../messages/messageLevel3.json" );
    // message.writeHeader();

    // message.writeInConsole( player_, &plug, 0 );
    
    UseWeapon useFist( levelNumber_, player_, &plug, "fist" );

    useFist.triggerAction();

    messageHandler.nextMessage();

    Selection::select(
        levelNumber_, 
        0, 
        { &useFist }
    );

    messageHandler.setIndexMessage( 2 );
    messageHandler.writeMessage();
    // message.writeInConsole( player_, &plug, 2 );

    Selection::select(
        levelNumber_, 
        1, 
        { &useFist }
    );

    messageHandler.nextMessage();

    Selection::select(
        levelNumber_, 
        2, 
        { &useFist }
    );

    messageHandler.nextMessage();

    player_->addWeapon( Weapon( "knife", 30, "Plantez !" ) );

    UseWeapon useKnife( levelNumber_, player_, &plug, "knife" );

    Selection::select(
        levelNumber_, 
        3, 
        { &useFist, &useKnife }
    );

    std::cout << "\n";
}
