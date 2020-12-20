#ifndef GAME_OVER_H
#define GAME_OVER_H

/*!
    * \file GameOver.h
*/

#include "Action.h"

class GameOver
{
    private:
        Player * const player_;

    public:
        explicit GameOver
        ( 
            Player * const player,
            const std::string& folderFromRoot,
            const std::string& fileName
        )
            Action( folderFromRoot, fileName ), 
            player_(player)
        {

        }

        void triggerAction() override const
        {
            player_->setDead( true );
        }
};

#endif