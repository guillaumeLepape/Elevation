/*!
    * \file ComboFistMeleeWeapon.cpp
*/

#include "ComboFistMeleeWeapon.h"
#include "Selection.h"

ComboFistMeleeWeapon::ComboFistMeleeWeapon
( 
    Player* const player
) :
    Combo( player )
{

}

void ComboFistMeleeWeapon::triggerCombo
(
    Plug* const plug,
    const int& resultChooseWeapon, 
    const std::vector<UseWeapon*>& useWeapon
)
{
    // if the player has attack with his fist, trigger the combo 
    // and the ennemy is not dead
    if ( (player_->weaponFromName( useWeapon[resultChooseWeapon]->nameWeapon() )).weaponType() == WeaponType::fist 
            && !( plug->deadOrNot() ) )
    {
        // Build vector of useWeapon actions without the fist action
        std::vector<Action*> useWeaponFistCombo; 

        for ( int i = 0; i < useWeapon.size(); i++ )
        {
            if ( useWeapon[i]->nameWeapon() != "fist" )
            {
                Weapon weapon( 
                    useWeapon[i]->nameWeapon() + "FistCombo",
                    (player_->weaponFromName( useWeapon[i]->nameWeapon() ).damageWeapon())/2,
                    WeaponType::meleeWeapon                
                );

                player_->addWeapon( weapon );

                useWeaponFistCombo.push_back(
                    new UseWeapon(
                        player_,
                        plug,
                        weapon.name(),
                        "data/Weapon",
                        weapon.nameUseWeapon()
                    )
                );
            }
        }

        Selection::select(
            useWeaponFistCombo,
            "data/Weapon",
            "selection0"
        );

        for ( int i = 0; i < useWeaponFistCombo.size(); i++ )
        {
            player_->deleteWeapon();
        }
    }       
}