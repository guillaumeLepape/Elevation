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

            // std::vector<int> listLevel = { 0, 1, 2, 3, 4 };
            std::vector<int> listLevel = { 4 };

            for ( auto i = listLevel.cbegin(); i != listLevel.cend(); i++ )
            {
                std::unique_ptr<Level> level = LevelFactory::newLevel( &player, *i );

                level->startLevel();
            }
        }
};

#endif