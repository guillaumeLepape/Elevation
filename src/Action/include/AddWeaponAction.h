#ifndef ADD_WEAPON_ACTION_H
#define ADD_WEAPON_ACTION_H

/*!
 * \file AddWeaponAction.h
 */

#include <memory>

#include "NameType.h"
#include "Player.h"
#include "Plug.h"
#include "Weapon.h"

namespace action {
class AddWeaponAction {
 private:
  Result result_;
  Player& player_;
  weapon::Weapon weapon_;

 public:
  AddWeaponAction(Player& player, weapon::Weapon&& weapon);

  void trigger();
};
}  // namespace action

#endif