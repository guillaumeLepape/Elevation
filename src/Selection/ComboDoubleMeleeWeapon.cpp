/*!
    * \file ComboDoubleMeleeWeapon.cpp
*/

#include "ComboDoubleMeleeWeapon.h"

#include "Nothing.h"
#include "Selection.h"

#include "WeaponFactory.h"

ComboDoubleMeleeWeapon::ComboDoubleMeleeWeapon( Player* const player ) :
    Combo( player )
{

}

void ComboDoubleMeleeWeapon::triggerCombo
( 
    Plug* const plug,
    const int& resultChooseWeapon,            
    const std::vector<UseWeapon*>& useWeapon
)
{
    const std::string& nameWeapon = useWeapon[resultChooseWeapon]->nameWeapon();

    if ( (player_->weaponFromName( nameWeapon ))->weaponType() == WeaponType::meleeWeapon 
            && !( plug->dead() ) )
    {
        UseWeapon useWeaponCombo
        ( 
            player_, 
            plug, 
            *( WeaponFactory::newWeapon( nameWeapon ) ), 
            *( data::Action::newStatementUseWeapon( nameWeapon ).get() ),
            data::Action::resultUseWeapon( plug->name(), player_->weaponFromName( nameWeapon )->damageWeapon() )
        );

        Nothing nothing
        (
            data::Combo::statementDontCombo,
            ""
        );

        int result = Selection::select(
            { &useWeaponCombo, &nothing },
            data::Combo::comboDoubleMeleeTitle
        );

        // if player choose to trigger combo, destroy the melee weapon
        if ( result == 0 )
        {
            player_->deleteWeapon( useWeapon[resultChooseWeapon]->nameWeapon() );
        }
    }
}