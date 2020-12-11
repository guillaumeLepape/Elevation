#ifndef USE_WEAPON_H
#define USE_WEAPON_H

/*!
    * \brief UseWeapon.h
*/

#include "Action.h"

class UseWeapon : public Action
{
    private:
        const Weapon& weapon_;
        Player* player_;
        Plug* plug_;

    public:
        UseWeapon( Player* player, Plug* plug, const std::string& nameWeapon ) : 
            Action( player->weaponFromName( nameWeapon ).statementAction() ),
            weapon_( player->weaponFromName( nameWeapon ) ),
            player_(player),
            plug_(plug)
        {}

        void triggerAction() const override
        {
            player_->changeWeapon( weapon_.name() );

            Message message( "../messages/messageHit.json" );
            message.writeInConsole( player_, plug_, 0 );

            plug_->decreaseLifePoints( weapon_.damageWeapon() );
        }
};

#endif