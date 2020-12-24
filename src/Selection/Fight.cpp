/*!
    * \file Fight.cpp
*/

#include "Fight.h"

#include <iostream>

#include "FightWriter.h"
#include "ChoosePlug.h"
#include "Selection.h"

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
            choosePlugActions.push_back( 
                new ChoosePlug( &(plugs_[i]), "data/ChoosePlug", "choosePlug" ) 
            ); 
        }

        int resultChoosePlug = Selection::select(
            choosePlugActions,
            "data/Level5",
            "select0"
        );

        std::cout << "\n " << resultChoosePlug;

        // UseWeapon useFist( player_, plugs_[0],  );

        // Selection(
            
        // );
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