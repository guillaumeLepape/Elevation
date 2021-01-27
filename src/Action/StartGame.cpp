/*!
    * \file StartGame.cpp
*/

#include "StartGame.h"

#include "Player.h"
#include "LevelFactory.h"
#include "Options.h"

StartGame::StartGame
(            
    const std::string& statement,
    const std::string& result,
    const Options& options,
    Player* const player 
) : 
    Action( statement, result ),
    player_( player ),
    options_( options )
{

}

void StartGame::triggerAction()
{       
    int i = 0;
    for ( i = player_->nbLevelSuceeded(); i < NB_LEVEL; i++ )
    {
        std::unique_ptr<Level> level = LevelFactory::newLevel( player_, options_, i );

        level->startLevel();
    }
}
