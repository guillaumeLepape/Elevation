#ifndef GAME_OVER_H
#define GAME_OVER_H

/*!
    * \file GameOver.h
*/

#include "WriteResults.h"

class GameOver : public Action
{
    private:
        const Player* const player_;

    public:
        explicit GameOver
        ( 
            const Player* const player,
            const std::string& folderFromRoot,
            const std::string& fileName
        ) :
            Action( folderFromRoot, fileName ),
            player_( player )
        {

        }

        explicit GameOver
        (
            const Player* const player,
            const std::tuple<bool, std::string>& statement,
            const std::tuple<bool, std::string>& result
        ) :
            Action( statement, result ),
            player_( player )
        {

        }

        void triggerAction() override
        {
            actionWriter_.writeResult();
            std::cout << "\n";
            exit(0);
        }
};

#endif