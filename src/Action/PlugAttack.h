#ifndef PLUG_ATTACK_H
#define PLUG_ATTACK_H

/*!
    * \file PlugAttack.h
*/

#include "Action.h"

class PlugAttack : public Action
{
    private:
        Player* const player_;
        const Plug* const plug_;

    public:
        PlugAttack
        (
            Player* const player, 
            const Plug* const plug,
            const std::string& statement,
            const std::string& result
        ) :
            Action( statement, result ),
            player_( player ),
            plug_( plug )
        {

        }


        void triggerAction() override
        {
            // if plug is not dead, he can attack
            if ( !(plug_->dead()) )
            {
                player_->decreaseLifePoints( plug_->weapon().damageWeapon() );
                actionWriter_.updateResult( data::Action::resultPlugAttack( plug_->name(), plug_->weapon().damageWeapon() ) );
                actionWriter_.writeResult();
            }
        }
};

#endif 