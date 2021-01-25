#ifndef REGENERATE_ALL_LIFE
#define REGENERATE_ALL_LIFE

/*!
    * \file RegenerateAllLife.h
*/

#include "Action.h"

class RegenerateAllLife : public Action
{
    private:
        Player* const player_;

    public:
        RegenerateAllLife( Player* const player, const std::string& statement, const std::string& result ) :
            Action( statement, result ),
            player_( player )
        {

        }

        void triggerAction() override
        {
            // if player is full life or dead, do nothing, else regenerate him
            if ( !(player_->fullLife()) && !(player_->dead()) )
            {
                actionWriter_.updateResult( data::Action::resultRegeneration( player_->missingLifePoints() ) );
                player_->increaseLifePoints( player_->missingLifePoints() );
                actionWriter_.writeResult();
            }
        }
};

#endif
