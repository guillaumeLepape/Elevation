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
            const std::string& folderFromRoot,
            const std::string& nameFile
        ) :
            Action( folderFromRoot, nameFile ),
            player_( player ),
            plug_( plug )
        {

        }

        PlugAttack
        (
            Player* const player, 
            const Plug* const plug,
            const std::tuple<bool, std::string>& statement,
            const std::tuple<bool, std::string>& result
        ) :
            Action( statement, result ),
            player_( player ),
            plug_( plug )
        {

        }


        void triggerAction() override
        {
            // if plug is not dead, he can attack
            if ( !(plug_->deadOrNot()) )
            {
                player_->decreaseLifePoints( plug_->weapon().damageWeapon() );
                actionWriter_.preTreatmentResult( player_, plug_ );
                actionWriter_.writeResult();
            }
        }
};

#endif 