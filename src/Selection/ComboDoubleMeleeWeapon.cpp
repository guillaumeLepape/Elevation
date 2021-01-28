/*!
    * \file ComboDoubleMeleeWeapon.cpp
*/

#include "ComboDoubleMeleeWeapon.h"

#include "Nothing.h"
#include "Selection.h"

#include "WeaponFactory.h"

ComboDoubleMeleeWeapon::ComboDoubleMeleeWeapon( Player* const player ) :
    Combo
    ( 
        player,
        data::Combo::titleDoubleMeleeWeapon,
        data::Combo::triggerStatementDoubleMeleeWeapon,
        data::Combo::triggeredStatementDoubleMeleeWeapon,
        data::Combo::malusStatementDoubleMeleeWeapon
    )
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

    if ( (nameWeapon == data::Weapon::nameKnife || nameWeapon == data::Weapon::nameHammer)
            && !( plug->dead() ) )
    {
        UseWeapon useWeaponCombo
        ( 
            player_, 
            plug, 
            WeaponFactory::newWeapon( nameWeapon ), 
            data::Weapon::resultUseWeapon( plug->name(), player_->weapons()->weaponFromName( nameWeapon )->damageWeapon() )
        );

        Nothing nothing
        (
            data::Combo::statementDontCombo,
            ""
        );

        int result = Selection::select(
            { &useWeaponCombo, &nothing },
            data::Combo::titleDoubleMeleeWeapon
        );

        // if player choose to trigger combo, destroy the melee weapon
        if ( result == 0 )
        {
            player_->weapons()->deleteWeapon( useWeapon[resultChooseWeapon]->nameWeapon() );
        }
    }
}