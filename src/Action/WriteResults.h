#ifndef WRITE_RESULTS_H
#define WRITE_RESULTS_H

/*!
    * \file WriteResults.h
*/

#include "Action.h"

#include "ResultsData.h"

class WriteResults : public Action
{
    private:
        const Player* const player_;
        const int levelNumber_;

    public:
        WriteResults
        (  
            const std::string& folderFromRoot,
            const std::string& nameFile,
            const Player* const player,
            const int& levelNumber
        ) :
            Action( folderFromRoot, nameFile ),
            player_( player ),
            levelNumber_( levelNumber )
        {

        }

        void triggerAction() override
        {
            ResultsData resultsData;
            resultsData.addResult( { player_->pseudo(), player_->id(), levelNumber_ } );
            resultsData.writeData();

            actionWriter_.writeResult();
            std::cout << "\n";
            exit(0);
        }
};

#endif