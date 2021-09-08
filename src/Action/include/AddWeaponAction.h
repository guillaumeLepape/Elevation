#ifndef ADD_WEAPON_ACTION_H
#define ADD_WEAPON_ACTION_H

/*!
 * \file AddWeaponAction.h
 */

#include <memory>

#include "NameType.h"
#include "Plug.h"
#include "Weapon.h"

class Player;

class AddWeaponAction {
 private:
  Result result_;
  Player* const player_;
  std::unique_ptr<const Weapon> weapon_;

 public:
  AddWeaponAction(Player* const player, std::unique_ptr<const Weapon>&& weapon);

  void triggerAction();
};

#endif