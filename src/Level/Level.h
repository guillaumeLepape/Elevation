#ifndef LEVEL_H
#define LEVEL_H

/*!
    * \file Level.h
*/

#include <memory>

#include "Options.h"
#include "Selection.h"
#include "Nothing.h"
#include "WriteResults.h"

#include "Languages.h"

class Level
{
    protected:
        Player* const player_;
        const int levelNumber_;

        void endOfLevel() const 
        {
            player_->nextLevel();

            std::unique_ptr<Action> continueAction( new Nothing( "data/Menu", "continue" ) );
            std::unique_ptr<Action> saveAndQuit( new WriteResults( "data/Menu", "writeResults", player_ ) );

            Selection::select(
                { continueAction.get(), saveAndQuit.get() },
                "data/Menu",
                "selection2"
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