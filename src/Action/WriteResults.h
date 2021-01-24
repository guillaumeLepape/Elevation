#ifndef WRITE_RESULTS_H
#define WRITE_RESULTS_H

/*!
    * \file WriteResults.h
*/

#include "Action.h"

class Player;

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
        );

        void triggerAction() override;
};

#endif