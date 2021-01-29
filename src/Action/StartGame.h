#ifndef START_GAME_H
#define START_GAME_H

/*!
    * \file StartGame.h
*/

#include "Action.h"

#include "Player.h"
#include "Id.h"

#include "ResultsData.h"

class Options;

class StartGame : public Action
{
    private:
        const std::unique_ptr<Player> player_;
        const std::unique_ptr<ResultsData> resultsData_;
        const Options& options_;

    public: 
        StartGame
        (
            const std::string& statement,
            const std::string& result,
            const Options& options,
            Player* const player 
                = new Player( "Joueur", Id::generateId(), 0 ),
            ResultsData* const resultsData 
                = new ResultsData()
        );

        StartGame( const StartGame& startGame ) = delete;
 
        void triggerAction() override;
};

#endif