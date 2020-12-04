/*!
    * \file Introduction.cpp
*/

#include "Introduction.h"

#include "../Action/Pseudo.h"

void Introduction::startLevel()
{
    Message message( "../messages/messageIntroduction.json" );
    message.writeHeader();
    message.writeInConsole( player_, nullptr, 0 );

    Pseudo pseudo( player_ );
    pseudo.triggerAction();

    message.writeInConsole( player_, nullptr, 1 );

    std::cout << "\n";
}