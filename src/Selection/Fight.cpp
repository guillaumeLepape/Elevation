/*!
    * \file Fight.cpp
*/

#include "Fight.h"

#include "Pause.h"

#include "FightWriter.h"
#include "ChoosePlug.h"
#include "PlugAttack.h"
#include "GameOver.h"
#include "Regeneration.h"

#include "Selection.h"

Fight::Fight
( 
    Player* const player, 
    const std::vector<Plug>& plugs, 
    const std::vector<Combo*>& combos,
    const bool& regeneration
) : 
    player_( player ),
    plugs_( plugs ),
    combos_( combos ),
    regeneration_( regeneration ),
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
                Action* choosePlug = 
                    new ChoosePlug
                    ( 
                        &(plugs_[i]), 
                        data::Action::statementChoosePlug(plugs_[i].name()), 
                        data::Action::resultChoosePlug(plugs_[i].name())
                    ); 
                choosePlugActions.push_back( choosePlug );
            }
        }

        int resultChoosePlug = Selection::select(
            choosePlugActions,
            data::Action::titleChoosePlug
        );

        const std::vector<const Weapon*> weapons = player_->weapons();

        std::vector<Action*> useWeapons;

        for ( int i = 0; i < weapons.size(); i++ )
        {
            Plug* plug = ( (ChoosePlug*) choosePlugActions[resultChoosePlug] )->plug();

            useWeapons.push_back(
                new UseWeapon(
                    player_,
                    plug,
                    *(weapons[i]),
                    *( data::Action::newStatementUseWeapon( (*(weapons[i])).name() ).get() ),
                    data::Action::resultUseWeapon( plug->name(), (*(weapons[i])).damageWeapon() )
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
            auto plug1 = ( (ChoosePlug*) choosePlugActions[resultChoosePlug] )->plug();
            auto useWeapons1 = (const std::vector<UseWeapon*>&) useWeapons;


            combos_[i]->triggerCombo( 
                plug1,
                resultUseWeapon, 
                useWeapons1 
            );
        }

        const int countNumberOfDeadPlug = methodNumberOfDeadPlug();

        if ( numberOfDeadPlug_ != countNumberOfDeadPlug )
        {
            numberOfDeadPlug_ = countNumberOfDeadPlug;
            fightWriter.writeRemoveDeadBody();
            player_->addWeapon( &((ChoosePlug*) choosePlugActions[resultChoosePlug])->plug()->weapon() );
        }

        for ( auto e = plugs_.cbegin(); e != plugs_.cend(); e++ )
        {
            PlugAttack plugAttack( player_, &(*e), "", data::Action::resultPlugAttack( e->name(), ((ChoosePlug*) choosePlugActions[resultChoosePlug])->plug()->weapon().damageWeapon()  ) );
            plugAttack.triggerAction();

            if ( player_->dead() )
            {
                GameOver gameOver( "", data::Menu::resultGameOver );
                gameOver.triggerAction();
            }
        }

        // If player is not dead, regenerate her
        if ( regeneration_ )
        {
            Regeneration regeneration( player_, "", "" );
            regeneration.triggerAction();
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
