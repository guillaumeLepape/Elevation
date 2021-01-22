#ifndef USE_WEAPON_H
#define USE_WEAPON_H

/*!
    * \brief UseWeapon.h
*/

#include "Languages.h"
#include "Dead.h"

#include "Player.h"
#include "Plug.h"

class UseWeapon : public Action
{
    private:
        const std::string nameWeapon_;
        Player* const player_;
        Plug* const plug_;

    public:
        UseWeapon
        (
            Player* const player, 
            Plug* const plug,
            const Weapon& weapon,
            const std::string& statement,
            const std::string& result
        ) : 
            Action( statement, result ),
            nameWeapon_( weapon.name() ),
            player_( player ),
            plug_( plug )
        {

        }

        void triggerAction() override
        {   
            const Weapon& weapon = player_->weaponFromName( nameWeapon_ );

            player_->changeWeapon( weapon.name() );
            plug_->decreaseLifePoints( weapon.damageWeapon() );

            actionWriter_.writeResult();
        
            Dead dead( plug_, "", data::Action::resultDead( plug_->name() ) );
            dead.triggerAction();
        }

        const std::string& nameWeapon() const { return nameWeapon_; }
};

#endif