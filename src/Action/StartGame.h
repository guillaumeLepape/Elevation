#ifndef START_GAME_H
#define START_GAME_H

#include "Action.h"
#include "../Level/Level1.h"
#include "../Player/Player.h"
#include "../Message/Message.h"

class StartGame : public Action
{
    public: 
        StartGame() {}
        void triggerAction() const
        {
            Message( "../messages/messageStartTime.json" );

            // Create Player instance
            Player player;

            // Create Level 1 instance
            Level1 level1;

            // Start the first level
            level1.startLevel();
        }
};

#endif