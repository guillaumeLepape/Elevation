#ifndef FIGHT_H
#define FIGHT_H

/*!
    * \file Fight.h
*/

#include "MessageHandler.h"
#include "Combo.h"

class Fight
{
    private:
        Player* const player_;
        std::vector<Plug>& plugs_;
        const MessageHandler& messageHandler_;
        const std::vector<Combo*>& combos_;

        const bool enemiesDeadOrNot() const;
    public:
        Fight
        ( 
            Player* const player, 
            std::vector<Plug>& plugs, 
            const MessageHandler& messageHandler,
            const std::vector<Combo*>& combos
        );

        void startFight();

};

#endif