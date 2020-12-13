#ifndef START_GAME_H
#define START_GAME_H

/*!
    * \file StartGame.h
*/

#include <memory>

#include "../Level/LevelFactory.h"

class StartGame : public Action
{
    public: 
        StartGame() : Action( "Commencer une partie" ) {}
        void triggerAction() const override
        {       
            Player player;

            int nbLevel = 4;

            for ( int i = 0; i <= 4; i++ )
            {
                std::unique_ptr<Level> level = LevelFactory::newLevel( &player, i );

                level->startLevel();
            }
        }
};

#endif