#ifndef ADD_WEAPON_ACTION_H
#define ADD_WEAPON_ACTION_H

/*!
 * \file AddWeaponAction.h
 */

#include <memory>

#include "Action.h"
#include "Plug.h"
#include "Weapon.h"

class Player;

class AddWeaponAction : public Action {
 private:
  Player* const player_;
  Plug* const plug_;
  const Weapon* weapon_;

 public:
  AddWeaponAction(Player* const player, Plug* const plug,
                  const std::string& statement, const std::string& result);

  AddWeaponAction(Player* const player, const Weapon* weapon,
                  const std::string& statement, const std::string& result);

  void triggerAction() override;
};

#endif