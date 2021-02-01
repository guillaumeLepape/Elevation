/*!
    * \file AddWeaponAction.cpp
*/

#include "AddWeaponAction.h"

#include "Player.h"

AddWeaponAction::AddWeaponAction
( 
    Player* const player,
    Plug* const plug,
    const std::string& statement, 
    const std::string& result 
) :
    Action( statement, result ),
    player_( player ),
    plug_( plug ),
    weapon_( nullptr )
{

}

AddWeaponAction::AddWeaponAction
(
    Player* const player,
    const Weapon* weapon,
    const std::string& statement, 
    const std::string& result  
) :
    Action( statement, result ),
    player_( player ),
    plug_( nullptr ),
    weapon_( weapon )
{

}


void AddWeaponAction::triggerAction()
{
    if ( weapon_ == nullptr )
    {
        if ( plug_->weapon()->weaponType() != WeaponType::noWeapon )
        {
            bool present = player_->weapons()->addWeapon( plug_->realeaseWeapon() );

            if ( !present )
            {
                actionWriter_.writeResult();
            }
        }
    }
    else
    {
        if ( weapon_->weaponType() != WeaponType::noWeapon )
        {
            bool present = player_->weapons()->addWeapon( weapon_ );

            if ( !present )
            {
                actionWriter_.writeResult();
            }
        }
    }
}