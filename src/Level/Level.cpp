/*!
    * \file Level.cpp
*/

#include "Level.h"

#include "Selection.h"
#include "Nothing.h"
#include "WriteResults.h"
#include "Quit.h"
#include "Languages.h"

Level::Level( Player* const player, const Options& options ) : 
    player_(player), options_(options)
{  
            
}

void Level::endOfLevel() const 
{
    player_->nextLevel();

    WriteResults writeResults( player_, data::Menu::statementSaveAndQuit, data::Menu::resultSaveAndQuit );
    writeResults.triggerAction();

    Nothing continueAction( data::Menu::statementContinue, "" );
    Quit quit( data::Menu::statementQuit, data::Menu::resultQuit );

    Selection::select(
        { &continueAction, &quit },
        data::Menu::titleContinueMenu
    );
}