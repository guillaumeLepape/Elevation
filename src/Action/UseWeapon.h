#ifndef USE_WEAPON_H
#define USE_WEAPON_H

/*!
    * \brief UseWeapon.h
*/

#include "Languages.h"
#include "Dead.h"

#include "Player.h"
#include "Plug.h"

#include "FireArm.h"

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
            const std::string& result
        ) : 
            Action( weapon.statement(), result ),
            nameWeapon_( weapon.name() ),
            player_( player ),
            plug_( plug )
        {

        }

        void triggerAction() override
        {   
            const Weapon* weapon = player_->weapons()->weaponFromName( nameWeapon_ );

            weapon->attack( plug_ );

            actionWriter_.writeResult();
        
            Dead dead( plug_, "", data::Action::resultDead( plug_->name() ) );
            dead.triggerAction();

            // if weapon is fireArm and has no ammo, delete it
            if ( weapon->weaponType() == WeaponType::fireArm )
            {
                if ( ((FireArm*) weapon)->nbAmmo() <= 0 )
                {
                    std::string nameWeapon = weapon->name();
                    player_->weapons()->deleteWeapon( nameWeapon );
                }
            }
        }

        const std::string& nameWeapon() const { return nameWeapon_; }
};

#endif