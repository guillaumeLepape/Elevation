#ifndef START_GAME_H
#define START_GAME_H

/*!
    * \file StartGame.h
*/

#include <memory>

#include "../Level/Introduction.h"
#include "../Level/Level1.h"
#include "../Level/Level2.h"
#include "../Level/Level3.h"

class StartGame : public Action
{
    public: 
        StartGame() : Action( "Commencer une partie" ) {}
        void triggerAction() const override
        {   
            // Create Player instance
            std::unique_ptr<Player> player(new Player);

            // Create Introduction
            Introduction introduction(player.get());
            // Start introduction
            introduction.startLevel();

            // Create Level 1 instance
            Level1 level1(player.get());
            // Start the first level
            level1.startLevel();

            // Create Level 2 instance
            Level2 level2(player.get());
            // Start the second level
            level2.startLevel();

            Level3 level3(player.get());
            level3.startLevel();
        }
};

#endif