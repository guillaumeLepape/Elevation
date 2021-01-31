#ifndef FIGHT_H
#define FIGHT_H

/*!
    * \file Fight.h
*/

#include "Combo.h"

struct ChooseWeaponResult
{
    int resultUseWeapon;
    std::vector<Action*> useWeapons;
};

class Fight
{
    private:
        Player* const player_;
        std::vector<Plug*> plugs_;
        std::vector<Combo*> combos_;
        bool regeneration_;

        int numberOfDeadPlug_;

        bool information_;
        bool noRule_;

        int methodNumberOfDeadPlug() const;
        bool enemiesDeadOrNot() const;

        Plug* const choosePlug();

        const ChooseWeaponResult chooseWeapon( Plug* const plug );

        void runCombos
        ( 
            Plug* const choosenPlug, 
            const int& resultUseWeapon, 
            const std::vector<Action*>& useWeapons 
        );
    public:
        Fight
        ( 
            Player* const player, 
            const std::vector<Plug*>& plugs, 
            const std::vector<Combo*>& combos,
            const bool& noRule,
            const bool& regeneration = true
        );

        void startFight();

};

#endif