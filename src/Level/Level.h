#ifndef LEVEL_H
#define LEVEL_H

/*!
    * \file Level.h
*/

#include "Languages.h"

#include "Options.h"
#include "Selection.h"
#include "Nothing.h"
#include "WriteResults.h"
#include "Quit.h"

class Level
{
    protected:
        Player* const player_;

        void endOfLevel() const 
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

    public:
        explicit Level( Player* const player ) : 
            player_(player)
        {  
            
        }
        virtual void startLevel( const Options& options ) = 0;
        virtual ~Level() = default;
};

#endif