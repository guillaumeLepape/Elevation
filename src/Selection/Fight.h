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
        std::vector<Plug>& plugs_;
        const std::vector<Combo*>& combos_;

        int numberOfDeadPlug_;

        const int methodNumberOfDeadPlug() const;
        const bool enemiesDeadOrNot() const;
    public:
        Fight
        ( 
            Player* const player, 
            std::vector<Plug>& plugs, 
            const std::vector<Combo*>& combos
        );

        void startFight();

};

#endif