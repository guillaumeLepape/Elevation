#ifndef WRITE_RESULTS_H
#define WRITE_RESULTS_H

/*!
    * \file WriteResults.h
*/

#include "Action.h"

#include "ResultsData.h"

#include <iostream>

class WriteResults : public Action
{
    private:
        const Player* const player_;

    public:
        WriteResults
        (
            const Player* const player,
            const std::string& statement,
            const std::string& result
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