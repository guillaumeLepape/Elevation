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
            // user cannot attack dead plugs
            if ( !(plugs_[i].deadOrNot()) )
            {
                Action* choosePlug = new ChoosePlug( &(plugs_[i]), "data/ChoosePlug", "choosePlug" ); 
                choosePlug->preTreatmentStatement( player_, &(plugs_[i]) );
                choosePlugActions.push_back( choosePlug );
            }
        }

        int resultChoosePlug = Selection::select(
            choosePlugActions,
            "data/Level5",
            "selection0"
        );

        auto weapons = player_->weapons();

        std::vector<Action*> useWeapons;

        for ( int i = 0; i < weapons.size(); i++ )
        {
            useWeapons.push_back(
                new UseWeapon(
                    player_,
                    ( (ChoosePlug*) choosePlugActions[resultChoosePlug] )->plug(),
                    weapons[i].name(),
                    "data/Weapon",
                    weapons[i].nameUseWeapon()
                )
            );
        }

        int resultUseWeapon = Selection::select(
            useWeapons,
            "data/Level5",
            "selection1"
        );

        fightWriter.writeRemoveDeadBody();
    }

    fightWriter.writeEndOfFight();

    std::cout << "\n";
}

const bool Fight::enemiesDeadOrNot() const
{
    bool result = true;

    for ( auto e = plugs_.cbegin(); e != plugs_.cend(); e++ )
    {
        result = result && e->deadOrNot();
    }

    return result;
}

// void Fight::removeDeadEnnemies() 
// {
//     Pause::pause();

//     std::cout << "\n " << "Evacuation des cadavres en cours.";

//     for ( auto e = plugs_.cbegin(); e != plugs_.cend(); e++ )
//     {
//         if ( e->deadOrNot() )
//         {
//             plugs_.erase( e );
//         }   
//     }
// }