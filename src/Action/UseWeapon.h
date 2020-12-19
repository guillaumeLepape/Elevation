#ifndef USE_WEAPON_H
#define USE_WEAPON_H

/*!
    * \brief UseWeapon.h
*/

#include "Action.h"
#include "../Plug/Plug.h"

class UseWeapon : public Action
{
    private:
        const Weapon& weapon_;
        Player* player_;
        Plug* plug_;

    public:
        UseWeapon( const int& levelNumber, const std::string& nameAction, Player* player, Plug* plug, const std::string& nameWeapon ) : 
            Action( levelNumber, nameAction, false ),
            weapon_( player->weaponFromName( nameWeapon ) ),
            player_(player),
            plug_(plug)
        {}

        void triggerAction() const override
        {
            player_->changeWeapon( weapon_.name() );
            
            actionWriter_.writeAction( player_, plug_ );

            plug_->decreaseLifePoints( weapon_.damageWeapon() );
        }
};

#endif