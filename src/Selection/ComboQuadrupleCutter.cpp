/*!
    * \file ComboQuadrupleCutter.cpp
*/

#include "ComboQuadrupleCutter.h"

#include "Languages.h"

ComboQuadrupleCutter::ComboQuadrupleCutter
( 
    Player* const player
) :
    Combo
    (
        player, 
        data::Combo::titleQuadrupleCutter,
        data::Combo::triggerStatementQuadrupleCutter,
        data::Combo::triggeredStatementQuadrupleCutter,
        data::Combo::malusStatementQuadrupleCutter
    )
{

}

void ComboQuadrupleCutter::triggerCombo
( 
    Plug* const plug,
    const int& resultChooseWeapon, 
    const std::vector<UseWeapon*>& useWeapon
)
{
    UseWeapon* useWeaponCombo = useWeapon[resultChooseWeapon];
    const std::string& nameWeapon = useWeaponCombo->nameWeapon();

    if ( nameWeapon == "Cutter" )
    {
        useWeaponCombo->triggerAction();
        useWeaponCombo->triggerAction();
        useWeaponCombo->triggerAction();
        player_->weapons()->deleteWeapon( nameWeapon );
    }   
}