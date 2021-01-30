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
#include "Nothing.h"
#include "InformationWeaponInventory.h"
#include "InformationCombo.h"
#include "AddWeaponAction.h"

#include "Selection.h"

Fight::Fight
( 
    Player* const player, 
    const std::vector<Plug>& plugs, 
    const std::vector<Combo*>& combos,
    const bool& noRule,
    const bool& regeneration
) : 
    player_( player ),
    plugs_( plugs ),
    combos_( combos ),
    regeneration_( regeneration ),
    numberOfDeadPlug_( 0 ),
    information_( true ),
    noRule_( noRule )
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

        if ( information_ && !noRule_ )
        {
            bool out = false;

            InformationWeaponInventory informationWeaponInventory( player_->weapons(), data::Information::statementInformationWeapon, "" );
            InformationCombo informationCombo( combos_, data::Information::statementInformationCombo, "" );
            Nothing noInformation( data::Information::statementNoInformation, "" );
            Nothing noInformationAnymore( data::Information::statementNoInformationAnymore, "" );

            while ( !out )
            {
                int resultInformation = Selection::select(
                    { &informationWeaponInventory, &informationCombo, &noInformation, &noInformationAnymore},
                    data::Information::titleInformation
                );

                // If the NoInformation option have been chosen, quit the while loop
                if ( resultInformation == 2 )
                {
                    out = true;
                }    
                // If the NoInformationAnymore option have been chosen, quit the while loop
                // and set information_ to true not display this selection for this fight
                else if ( resultInformation == 3 )
                {
                    out = true;
                    information_ = false;
                }   
            }
        }

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

        const std::vector<const Weapon*>* weapons = player_->weapons();

        std::vector<Action*> useWeapons;

        Plug* const choosenPlug = ( (ChoosePlug*) choosePlugActions[resultChoosePlug] )->plug();

        for ( auto w = weapons->cbegin(); w != weapons->cend(); w++ )
        {
            useWeapons.push_back(
                new UseWeapon(
                    player_,
                    choosenPlug,
                    *w,
                    data::Weapon::resultUseWeapon( choosenPlug->name(), (*w)->damageWeapon() )
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
            const Weapon* weapon
            (
                ((ChoosePlug*) choosePlugActions[resultChoosePlug])->plug()->weapon()
            );
            AddWeaponAction addWeaponAction
            ( 
                player_, 
                weapon, 
                "", 
                data::Action::resultAddWeapon(weapon->name()) 
            );
            addWeaponAction.triggerAction();

            fightWriter.writeRemoveDeadBody();
        }

        for ( auto e = plugs_.begin(); e != plugs_.end(); e++ )
        {
            PlugAttack plugAttack( player_, &(*e), "", data::Action::resultPlugAttack( e->name(), ((ChoosePlug*) choosePlugActions[resultChoosePlug])->plug()->weapon()->damageWeapon()  ) );
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

        for ( int i = 0; i < choosePlugActions.size(); i++ )
        {
            delete choosePlugActions[i];
        }
        for ( int i = 0; i < useWeapons.size(); i++ )
        {
            delete useWeapons[i];
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
