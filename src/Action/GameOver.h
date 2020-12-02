#ifndef GAME_OVER_H
#define GAME_OVER_H

#include "Action.h"

class GameOver
{
    private:
        Player * const player_;
    public:
        explicit GameOver
        ( 
            Player * const player 
        )
            Action( player_ )
        {

        }

        void triggerAction() override const
        {
            player_->setDead( true );
        }
};

#endif