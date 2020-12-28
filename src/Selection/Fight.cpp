/*!
    * \file Fight.cpp
*/

#include "Fight.h"

#include <iostream>

#include "FightWriter.h"
#include "ChoosePlug.h"
#include "Selection.h"
#include "UseWeapon.h"

Fight::Fight
( 
    Player* const player, 
    std::vector<Plug>& plugs, 
    const MessageHandler& messageHandler 
) : 
    player_( player ),
    plugs_( plugs ),
    messageHandler_( messageHandler )
{

}

void Fight::startFight()
{
    int nbTurns = 0;

    FightWriter fightWriter( player_, plugs_ );

    // while all enemies are not dead or player is not dead
    while ( !enemiesDeadOrNot() && !player_->dead() && nbTurns < 1000 )
    {
        nbTurns++;

        fightWriter.writeHeader( nbTurns );
        fightWriter.writeGameBoard();

        std::vector<Action*> choosePlugActions;

        for ( int i = 0; i < plugs_.size(); i++ )
        {
            Action* choosePlug = new ChoosePlug( &(plugs_[i]), "data/ChoosePlug", "choosePlug" ); 
            choosePlug->preTreatmentStatement( player_, &(plugs_[i]) );

            choosePlugActions.push_back( choosePlug );
        }

        int resultChoosePlug = Selection::select(
            choosePlugActions,
            "data/Level5",
            "selection0"
        );

        UseWeapon useFist
        ( 
            player_, 
            &(plugs_[resultChoosePlug]), 
            "fist", 
            "data/Weapon", 
            "useFist" 
        );

        UseWeapon useKnife
        ( 
            player_, 
            &(plugs_[resultChoosePlug]),
            "knife",
            "data/Weapon",
            "useKnife" 
        );

        UseWeapon useHammer
        (
            player_,
            &(plugs_[resultChoosePlug]),
            "hammer",
            "data/Weapon",
            "useHammer"
        );

        Selection::select(
            { &useFist, &useKnife, &useHammer },
            "data/Level5",
            "selection1"
        );

        fightWriter.writeGameBoard();


    }



}

const bool Fight::enemiesDeadOrNot() const
{
    bool result = false;

    for ( auto e = plugs_.cbegin(); e != plugs_.cend(); e++ )
    {
        result = result || e->deadOrNot();
    }

    return result;
}