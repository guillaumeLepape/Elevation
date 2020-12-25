#ifndef USE_WEAPON_H
#define USE_WEAPON_H

/*!
    * \brief UseWeapon.h
*/

#include "Dead.h"

class UseWeapon : public Action
{
    private:
        const Weapon& weapon_;
        Player* const player_;
        Plug* const plug_;

    public:
        UseWeapon
        ( 
            Player* const player, 
            Plug* const plug, 
            const std::string& nameWeapon,
            const std::string& folderFromRoot,
            const std::string& nameFile
        ) : 
            Action( folderFromRoot, nameFile ),
            weapon_( player->weaponFromName( nameWeapon ) ),
            player_(player),
            plug_(plug)
        {}

        void triggerAction() override
        {
            player_->changeWeapon( weapon_.name() );
            plug_->decreaseLifePoints( weapon_.damageWeapon() );

            actionWriter_.preTreatmentResult( player_, plug_ );
            actionWriter_.writeResult();
        
            Dead dead( player_, plug_, "data/Dead", "dead" );
            dead.preTreatmentResult( player_, plug_ );
            dead.triggerAction();
        }
};

#endif