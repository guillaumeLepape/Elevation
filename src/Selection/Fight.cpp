/*!
    * \file Fight.cpp
*/

#include "Fight.h"

#include <iostream>

#include "../Writer/FightWriter.h"

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