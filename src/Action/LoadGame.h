#ifndef LOAD_GAME_H
#define LOAD_GAME_H

/*!
    * \file LoadGame.h
*/

#include "Action.h"

// forward declaration of Options class
class Options;

class LoadGame : public Action
{
    private:
        const Options& options_;

    public:
        LoadGame
        (
            const std::string& statement,
            const std::string& result,
            const Options& options
        );

        void triggerAction() override;
};

#endif