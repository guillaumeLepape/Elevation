#ifndef REGENERATION_H
#define REGENERATION_H

/*!
    * \file Regeneration.h
*/

#include "Action.h"

class Regeneration : public Action
{
    private:
        Player* const player_;

    public :
        Regeneration
        ( 
            Player* const player, 
            const std::string& statement, 
            const std::string& result 
        ) :  
            Action( statement, result ),
            player_( player )
        {

        }

        void triggerAction() override
        {
            int nbLifePointsRegeneration = 0;

            switch (player_->nbLevelSuceeded())
            {
                case 0 ... 4:
                    nbLifePointsRegeneration = 10;
                    break;
                case 5:
                    nbLifePointsRegeneration = 20;
                    break;
                default:
                    nbLifePointsRegeneration = 0;
                    break;
            }
            player_->increaseLifePoints( nbLifePointsRegeneration );
            actionWriter_.preTreatmentStatement( player_, nullptr );
            actionWriter_.writeResult();
        }
};

#endif