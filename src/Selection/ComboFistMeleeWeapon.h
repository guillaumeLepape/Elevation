#ifndef COMBO_FIST_WEAPON_H
#define COMBO_FIST_WEAPON_H

/*!
    * \file ComboFistMeleeWeapon.h
*/

#include "Combo.h"

class ComboFistMeleeWeapon : public Combo
{
    public:
        ComboFistMeleeWeapon
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