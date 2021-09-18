/*!
 * \file AddWeaponAction.cpp
 */

#include "AddWeaponAction.h"

#include "ActionWriter.h"
#include "Player.h"

AddWeaponAction::AddWeaponAction(Player& player,
                                 std::unique_ptr<const Weapon>&& weapon)
    : result_{data::Action::resultAddWeapon(weapon->name())},
      player_{player},
      weapon_{std::move(weapon)} {}

void AddWeaponAction::triggerAction() {
  if (weapon_->weaponType() != WeaponType::noWeapon) {
    bool present = player_.weapons().addWeapon(std::move(weapon_));

    if (!present) {
      Action::writeResult(result_);
    }
  }
}