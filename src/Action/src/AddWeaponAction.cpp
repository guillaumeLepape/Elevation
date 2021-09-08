/*!
 * \file AddWeaponAction.cpp
 */

#include "AddWeaponAction.h"

#include "ActionWriter.h"
#include "Player.h"

AddWeaponAction::AddWeaponAction(Player* const player, Plug* const plug,
                                 const Result& result)
    : result_(result), player_(player), plug_(plug), weapon_(nullptr) {}

AddWeaponAction::AddWeaponAction(Player* const player, const Weapon* weapon,
                                 const Result& result)
    : result_(result), player_(player), plug_(nullptr), weapon_(weapon) {}

void AddWeaponAction::triggerAction() {
  if (weapon_ == nullptr) {
    if (plug_->weapon()->weaponType() != WeaponType::noWeapon) {
      bool present = player_->weapons()->addWeapon(plug_->realeaseWeapon());

      if (!present) {
        Action::writeResult(result_);
      }
    }
  } else {
    if (weapon_->weaponType() != WeaponType::noWeapon) {
      bool present =
          player_->weapons()->addWeapon(std::unique_ptr<const Weapon>(weapon_));

      if (!present) {
        Action::writeResult(result_);
      }
    }
  }
}