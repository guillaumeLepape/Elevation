#ifndef COMBO_H
#define COMBO_H

/*!
    * \file Combo.h
*/

#include "UseWeapon.h"

class Combo
{
    protected:
        Player* const player_;

    public:
        Combo( Player* const player ) :
            player_( player )
        {

        }

        virtual void triggerCombo
        ( 
            Plug* const plug,
            const int& resultChooseWeapon, 
            const std::vector<UseWeapon*>& useWeapon
        ) = 0;
};

#endif