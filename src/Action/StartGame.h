#ifndef START_GAME_H
#define START_GAME_H

#include "Action.h"
#include "../Level/Level1.h"
#include "../Player/Player.h"

class StartGame : public Action
{
    public: 
        StartGame() {}
        void triggerAction() const
        {
            Player player;
            Level1 level1;
            level1.startLevel();
        }
};

#endif