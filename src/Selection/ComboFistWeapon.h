#ifndef COMBO_FIST_WEAPON_H
#define COMBO_FIST_WEAPON_H

/*!
    * \file ComboFistWeapon.h
*/

#include "Combo.h"

class ComboFistWeapon : public Combo
{
    public:
        ComboFistWeapon
        ( 
            Player* const player
        );

        void triggerCombo
        ( 
            Plug* const plug,
            const int& resultChooseWeapon, 
            const std::vector<UseWeapon*>& useWeapon
        ) override;
};

#endif