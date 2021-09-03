#ifndef ADD_WEAPON_ACTION_H
#define ADD_WEAPON_ACTION_H

/*!
 * \file AddWeaponAction.h
 */

#include <memory>

#include "ActionWriter.h"
#include "NameType.h"
#include "Plug.h"
#include "Weapon.h"

class Player;

class AddWeaponAction {
 private:
  ActionWriter actionWriter_;

  Player* const player_;
  Plug* const plug_;
  const Weapon* weapon_;

 public:
  AddWeaponAction(Player* const player, Plug* const plug, const Result& result);

  AddWeaponAction(Player* const player, const Weapon* weapon,
                  const Result& result);

  void triggerAction();
};

#endif