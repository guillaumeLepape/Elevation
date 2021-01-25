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

        for ( auto p = plugs_.begin(); p != plugs_.end(); p++ )
        {
            // user cannot attack dead plugs
            if ( !p->dead() )
            {
                Action* choosePlug = 
                    new ChoosePlug
                    ( 
                        &(*p), 
                        data::Action::statementChoosePlug(p->name()), 
                        data::Action::resultChoosePlug(p->name())
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

        Plug* const choosenPlug = ( (ChoosePlug*) choosePlugActions[resultChoosePlug] )->plug();

        for ( auto w = weapons.cbegin(); w != weapons.cend(); w++ )
        {
            useWeapons.push_back(
                new UseWeapon(
                    player_,
                    choosenPlug,
                    **w,
                    *( data::Action::newStatementUseWeapon( (*w)->name() ).get() ),
                    data::Action::resultUseWeapon( choosenPlug->name(), (*w)->damageWeapon() )
                )
            );
        }

        int resultUseWeapon = Selection::select(
            useWeapons,
            data::Action::titleChooseWeapon
        );


        // launch every combo
        for ( auto c = combos_.cbegin(); c != combos_.cend(); c++ )
        {
            (*c)->triggerCombo( 
                choosenPlug,
                resultUseWeapon, 
                (const std::vector<UseWeapon*>&) useWeapons 
            );
        }

        const int countNumberOfDeadPlug = methodNumberOfDeadPlug();

        if ( numberOfDeadPlug_ != countNumberOfDeadPlug )
        {
            numberOfDeadPlug_ = countNumberOfDeadPlug;
            fightWriter.writeRemoveDeadBody();
            const Weapon* weapon = new Weapon
            (
                ((ChoosePlug*) choosePlugActions[resultChoosePlug])->plug()->weapon()
            );
            player_->addWeapon( weapon );
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

bool Fight::enemiesDeadOrNot() const
{
    bool result = true;

    for ( auto e = plugs_.cbegin(); e != plugs_.cend(); e++ )
    {
        result = result && e->dead();
    }

    return result;
}

int Fight::methodNumberOfDeadPlug() const
{
    int numberOfDead = 0;
    for ( auto e = plugs_.cbegin(); e != plugs_.cend(); e++ )
    {
        if ( e->dead() )
        {
            numberOfDead++;
        }
    } 
    return numberOfDead;
}
