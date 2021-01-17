#ifndef LEVEL_H
#define LEVEL_H

/*!
    * \file Level.h
*/

#include "Options.h"
#include "Selection.h"
#include "Nothing.h"
#include "WriteResults.h"

class Level
{
    protected:
        Player* const player_;
        const int levelNumber_;

        void endOfLevel() const 
        {
            player_->nextLevel();

            std::unique_ptr<Action> continueAction( new Nothing( data::Menu::statementContinue, std::tuple<bool, std::string>() ) );
            std::unique_ptr<Action> saveAndQuit( new WriteResults( player_, data::Menu::statementSaveAndQuit, data::Menu::resultSaveAndQuit ) );

            Selection::select(
                { continueAction.get(), saveAndQuit.get() },
                data::Menu::titleContinueMenu
            );
        }

    public:
        explicit Level( Player* const player, const int& levelNumber ) : 
            player_(player),
            levelNumber_( levelNumber )
        {  
            
        }
        virtual void startLevel( const Options& options ) = 0;
        virtual ~Level() {}
};

#endif