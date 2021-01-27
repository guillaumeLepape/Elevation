/*!
    * \file AddWeaponAction.cpp
*/

#include "AddWeaponAction.h"

#include "Player.h"

AddWeaponAction::AddWeaponAction
( 
    Player* const player,
    const Weapon* const weapon,
    const std::string& statement, 
    const std::string& result 
) :
    Action( statement, result ),
    player_( player ),
    weapon_( weapon )
{

}


void AddWeaponAction::triggerAction()
{
    bool present = player_->weapons()->addWeapon( weapon_ );

    if ( !present )
    {
        actionWriter_.writeResult();
    }
}