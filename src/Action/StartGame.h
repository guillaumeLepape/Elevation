#ifndef START_GAME_H
#define START_GAME_H

/*!
    * \file StartGame.h
*/

#include "Action.h"

#include "Player.h"
#include "Id.h"

class Options;

class StartGame : public Action
{
    private:
        Player* const player_;
        const Options& options_;

    public: 
        StartGame
        (
            const std::string& statement,
            const std::string& result,
            const Options& options,
            Player* const player 
                = new Player( "Joueur", Id::generateId(), 0 ) 
        );

        void triggerAction() override;
};

#endif