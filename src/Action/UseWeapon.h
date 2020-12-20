#ifndef USE_WEAPON_H
#define USE_WEAPON_H

/*!
    * \brief UseWeapon.h
*/

#include "Action.h"
#include "../Plug/Plug.h"

#include "Dead.h"

class UseWeapon : public Action
{
    private:
        const Weapon& weapon_;
        Player* player_;
        Plug* plug_;

    public:
        UseWeapon
        ( 
            Player* player, 
            Plug* plug, 
            const std::string& nameWeapon,
            const std::string& folderFromRoot,
            const std::string& nameFile
        ) : 
            Action( folderFromRoot, nameFile ),
            weapon_( player->weaponFromName( nameWeapon ) ),
            player_(player),
            plug_(plug)
        {}

        void triggerAction() const override
        {
            player_->changeWeapon( weapon_.name() );
            plug_->decreaseLifePoints( weapon_.damageWeapon() );

            actionWriter_.writeResult( player_, plug_ );
        
            Dead dead( player_, plug_, "data/Dead", "dead" );
            dead.triggerAction();
        }
};

#endif