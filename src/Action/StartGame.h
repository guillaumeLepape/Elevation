#ifndef START_GAME_H
#define START_GAME_H

/*!
    * \file StartGame.h
*/

#include <memory>

#include "LevelFactory.h"

class StartGame : public Action
{
    public: 
        StartGame
        ( 
            const std::string& folderFromRoot, 
            const std::string& nameFile 
        ) : 
            Action( folderFromRoot, nameFile ) 
        {

        }

        void triggerAction() override
        {       
            Player player;

            std::vector<int> listLevel = { 0, 1, 2, 3, 4, 5 };

            for ( auto i = listLevel.cbegin(); i != listLevel.cend(); i++ )
            {
                std::unique_ptr<Level> level = LevelFactory::newLevel( &player, *i );

                level->startLevel();
            }
        }
};

#endif