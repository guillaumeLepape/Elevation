#ifndef FIGHT_H
#define FIGHT_H

/*!
    * \file Fight.h
*/

#include "MessageHandler.h"

class Fight
{
    private:
        Player* const player_;
        std::vector<Plug>& plugs_;
        const MessageHandler& messageHandler_;

        const bool enemiesDeadOrNot() const;
    public:
        Fight
        ( 
            Player* const player, 
            std::vector<Plug>& plugs, 
            const MessageHandler& messageHandler 
        );

        void startFight();

};

#endif