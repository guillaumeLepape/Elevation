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

    if ( (player_->weaponFromName( nameWeapon )).weaponType() == WeaponType::meleeWeapon 
            && !( plug->deadOrNot() ) )
    {
        std::unique_ptr<Action> useWeaponCombo
        ( 
            new UseWeapon(
                player_, 
                plug, 
                *( WeaponFactory::newWeapon( nameWeapon ).get() ), 
                *( data::Action::newStatementUseWeapon( nameWeapon ).get() ),
                data::Action::resultUseWeapon
            )
        );

        std::unique_ptr<Action> nothing(
            new Nothing(
                data::Combo::statementDontCombo,
                std::tuple<bool, std::string>()
            )
        );

        int result = Selection::select(
            { useWeaponCombo.get(), nothing.get() },
            data::Combo::comboDoubleMeleeTitle
        );

        // if player choose to trigger combo, destroy the melee weapon
        if ( result == 0 )
        {
            player_->deleteWeapon( useWeapon[resultChooseWeapon]->nameWeapon() );
        }
    }
}