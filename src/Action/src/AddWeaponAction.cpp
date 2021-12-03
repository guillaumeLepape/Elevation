/*!
 * \file AddWeaponAction.cpp
 */

#include "AddWeaponAction.h"

#include "ActionWriter.h"
#include "Player.h"

AddWeaponAction::AddWeaponAction(Player& player, weapon::Weapon&& weapon)
    : result_{data::Action::resultAddWeapon(weapon.name)},
      player_{player},
      weapon_{std::move(weapon)} {}

void AddWeaponAction::triggerAction() {
  if (weapon_.type != weapon::Type::noWeapon) {
    auto [_, present] = player_.weapons().insert(std::move(weapon_));

    if (not present) {
      Action::writeResult(result_);
    }
  }
}