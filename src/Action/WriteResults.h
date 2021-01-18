#ifndef WRITE_RESULTS_H
#define WRITE_RESULTS_H

/*!
    * \file WriteResults.h
*/

#include "Action.h"

class WriteResults : public Action
{
    private:
        const Player* const player_;

    public:
        WriteResults
        (  
            const std::string& folderFromRoot,
            const std::string& nameFile,
            const Player* const player
        ) :
            Action( folderFromRoot, nameFile ),
            player_( player )
        {

        }

        WriteResults
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
            ResultsData resultsData;
            resultsData.addResult( *player_ );
            resultsData.writeData();

            actionWriter_.writeResult();
            std::cout << "\n";
        }
};

#endif