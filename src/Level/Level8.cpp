/*!
    * \file Level8.cpp
*/

#include "Level8.h"

#include <iostream>

#include "HeaderWriter.h"
#include "MessageWriter.h"

#include "Plug.h"

#include "Ninemm.h"

#include "AddWeaponAction.h"

#include "Languages.h"

void Level8::startLevel()
{
    Plug plug( "Mathilde", 30 );

    HeaderWriter headerWriter( data::Level8::nameLevel, data::Level8::hour, data::Level8::minut );
    headerWriter.writeHeader();

    MessageWriter messageWriter0
    ( 
        data::Level8::message0( plug.name() ), 
        player_->name(),  
        plug.name()
    );
    messageWriter0.writeMessage();

    const Ninemm* ninemm = new Ninemm(3);
    AddWeaponAction addWeaponAction
    ( 
        player_, 
        ninemm, 
        "", 
        data::Action::resultAddWeapon(ninemm->name()) 
    );
    addWeaponAction.triggerAction();

    MessageWriter messageWriter1
    (
        data::Level8::message1, 
        player_->name(),
        plug.name()
    );
    messageWriter1.writeMessage();

    Level::endOfLevel();

    std::cout << "\n";
}