#ifndef PLUG_ATTACK_H
#define PLUG_ATTACK_H

/*!
 * \file PlugAttack.h
 */

#include "NameType.h"

class PlugAttack {
 private:
  ActionWriter actionWriter_;

  Player* const player_;
  Plug* const plug_;

 public:
  PlugAttack(Player* const player, Plug* const plug, const Result& result)
      : actionWriter_("", result.get()), player_(player), plug_(plug) {}

  void triggerAction() {
    // if plug is not dead and has a weapon, he can attack
    if (!(plug_->dead()) &&
        plug_->weapon()->weaponType() != WeaponType::noWeapon) {
      plug_->weapon()->attack(player_);
      actionWriter_.updateResult(
          data::Action::resultPlugAttack(plug_->name(),
                                         plug_->weapon()->damageWeapon())
              .get());
      actionWriter_.writeResult();
    }
  }
};

#endif