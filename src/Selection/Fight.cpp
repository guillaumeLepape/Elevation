/*!
    * \file Fight.cpp
*/

#include "Fight.h"

#include "FightWriter.h"
#include "ChoosePlug.h"
#include "PlugAttack.h"
#include "GameOver.h"
#include "Selection.h"

Fight::Fight
( 
    Player* const player, 
    std::vector<Plug>& plugs, 
    const std::vector<Combo*>& combos
) : 
    player_( player ),
    plugs_( plugs ),
    combos_( combos ),
    numberOfDeadPlug_( 0 )
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
                Action* choosePlug = new ChoosePlug( &(plugs_[i]), data::Action::statementChoosePlug, data::Action::resultChoosePlug ); 
                choosePlug->preTreatmentStatement( player_, &(plugs_[i]) );
                choosePlugActions.push_back( choosePlug );
            }
        }

        int resultChoosePlug = Selection::select(
            choosePlugActions,
            data::Action::titleChoosePlug
        );

        std::vector<Weapon> weapons = player_->weapons();

        std::vector<Action*> useWeapons;

        for ( int i = 0; i < weapons.size(); i++ )
        {
            useWeapons.push_back(
                new UseWeapon(
                    player_,
                    ( (ChoosePlug*) choosePlugActions[resultChoosePlug] )->plug(),
                    weapons[i],
                    *( data::Action::newStatementUseWeapon( weapons[i].name() ).get() ),
                    data::Action::resultUseWeapon
                )
            );
        }

        int resultUseWeapon = Selection::select(
            useWeapons,
            data::Action::titleChooseWeapon
        );

        // launch every combo
        for ( int i = 0; i < combos_.size(); i++ )
        {
            combos_[i]->triggerCombo( 
                ( (ChoosePlug*) choosePlugActions[resultChoosePlug] )->plug(),
                resultUseWeapon, 
                (const std::vector<UseWeapon*>&) useWeapons 
            );
        }

        const int countNumberOfDeadPlug = methodNumberOfDeadPlug();

        if ( numberOfDeadPlug_ != countNumberOfDeadPlug )
        {
            numberOfDeadPlug_ = countNumberOfDeadPlug;
            fightWriter.writeRemoveDeadBody();
            player_->addWeapon( ((ChoosePlug*) choosePlugActions[resultChoosePlug])->plug()->weapon() );
        }

        for ( auto e = plugs_.cbegin(); e != plugs_.cend(); e++ )
        {
            PlugAttack plugAttack( player_, &(*e), std::tuple<bool, std::string>(), data::Action::resultPlugAttack );
            plugAttack.triggerAction();

            if ( player_->dead() )
            {
                GameOver gameOver( player_, std::tuple<bool, std::string>(), data::Menu::resultGameOver );
                gameOver.triggerAction();
            }
        }

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

const int Fight::methodNumberOfDeadPlug() const
{
    int numberOfDead = 0;
    for ( auto e = plugs_.cbegin(); e != plugs_.cend(); e++ )
    {
        if ( e->deadOrNot() )
        {
            numberOfDead++;
        }
    } 
    return numberOfDead;
}
