/*!
    * \file ComboFistMeleeWeapon.cpp
*/

#include "ComboFistMeleeWeapon.h"
#include "Selection.h"

#include "WeaponFactory.h"

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
    // and player has at least one melee weapon
    if ( (player_->weapons().weaponFromName( useWeapon[resultChooseWeapon]->nameWeapon() ))->weaponType() == WeaponType::fist 
            && !( plug->dead() ) && player_->weapons().containWeaponType( WeaponType::meleeWeapon ))
    {
        // Build vector of useWeapon actions without the fist action
        std::vector<Action*> useWeaponFistCombo; 

        for ( int i = 0; i < useWeapon.size(); i++ )
        {
            const std::string& nameWeapon = useWeapon[i]->nameWeapon();

            // Generate combo weapon, if the weapon is a melee weapon
            if ( (player_->weapons().weaponFromName( nameWeapon ))->weaponType() == WeaponType::meleeWeapon )
            {
                const Weapon* weaponFistCombo 
                    = WeaponFactory::newWeaponFistCombo( useWeapon[i]->nameWeapon() );

                player_->weapons().addWeapon( weaponFistCombo );

                useWeaponFistCombo.push_back(
                    new UseWeapon(
                        player_,
                        plug,
                        *weaponFistCombo,
                        *(data::Action::newStatementUseWeapon( weaponFistCombo->name() ).get()),
                        data::Action::resultUseWeapon( plug->name(), weaponFistCombo->damageWeapon() )
                    )
                );
            }
        }

        Selection::select(
            useWeaponFistCombo,
            data::Combo::comboFistMeleeWeaponComboTitle
        );

        for ( int i = 0; i < useWeaponFistCombo.size(); i++ )
        {
            player_->weapons().deleteWeapon( ((UseWeapon*) useWeaponFistCombo[i])->nameWeapon() );
        }
    }       
}