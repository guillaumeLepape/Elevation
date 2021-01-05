/*!
    * \file ComboDoubleMeleeWeapon.cpp
*/

#include "ComboDoubleMeleeWeapon.h"

#include "Nothing.h"
#include "Selection.h"

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
    if ( (player_->weaponFromName( useWeapon[resultChooseWeapon]->nameWeapon() )).weaponType() == WeaponType::meleeWeapon 
            && !( plug->deadOrNot() ) )
    {
        std::unique_ptr<Action> useWeaponCombo
        ( 
            new UseWeapon(
                player_, 
                plug, 
                useWeapon[resultChooseWeapon]->nameWeapon(), 
                "data/Weapon",
                (player_->weaponFromName( useWeapon[resultChooseWeapon]->nameWeapon() )).nameUseWeapon()
            )
        );

        std::unique_ptr<Action> nothing(
            new Nothing(
                "data/Weapon",
                "dontCombo"
            )
        );

        int result = Selection::select(
            { useWeaponCombo.get(), nothing.get() },
            "data/Weapon",
            "comboDoubleMelee"
        );

        // if player choose to trigger combo, destroy the melee weapon
        if ( result == 0 )
        {
            player_->deleteWeapon( useWeapon[resultChooseWeapon]->nameWeapon() );
        }
    }
}