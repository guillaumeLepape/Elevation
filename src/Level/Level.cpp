/*!
    * \file Level.cpp
*/

#include "Level.h"

#include "Selection.h"
#include "Nothing.h"
#include "WriteResults.h"
#include "Quit.h"
#include "Languages.h"

Level::Level( Player* const player ) : 
    player_(player)
{  
            
}

void Level::endOfLevel() const 
{
    player_->nextLevel();

    WriteResults writeResults( player_, data::Menu::statementSaveAndQuit, data::Menu::resultSaveAndQuit );
    writeResults.triggerAction();

    Nothing continueAction( data::Menu::statementContinue, "" );
    Quit quit( data::Menu::statementSaveAndQuit, data::Menu::resultSaveAndQuit );

    Selection::select(
        { &continueAction, &quit },
        data::Menu::titleContinueMenu
    );
}