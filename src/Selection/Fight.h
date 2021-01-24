#ifndef FIGHT_H
#define FIGHT_H

/*!
    * \file Fight.h
*/

#include "Combo.h"

class Fight
{
    private:
        Player* const player_;
        std::vector<Plug> plugs_;
        std::vector<Combo*> combos_;
        bool regeneration_;

        int numberOfDeadPlug_;

        int methodNumberOfDeadPlug() const;
        bool enemiesDeadOrNot() const;
    public:
        Fight
        ( 
            Player* const player, 
            const std::vector<Plug>& plugs, 
            const std::vector<Combo*>& combos,
            const bool& regeneration = true
        );

        void startFight();

};

#endif