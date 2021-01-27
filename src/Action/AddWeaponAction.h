#ifndef ADD_WEAPON_ACTION_H
#define ADD_WEAPON_ACTION_H

/*!
    * \file AddWeaponAction.h
*/

#include "Action.h"

#include "Weapon.h"

class Player;

class AddWeaponAction : public Action
{
    private:
        Player* const player_;
        const Weapon* weapon_;

    public:
        AddWeaponAction
        ( 
            Player* const player,
            const Weapon* weapon,
            const std::string& statement, 
            const std::string& result 
        );

        void triggerAction() override;
};

#endif