#ifndef PLUG_ATTACK_H
#define PLUG_ATTACK_H

/*!
 * \file PlugAttack.h
 */

#include "NameType.h"

namespace action {
class PlugAttack {
 private:
  Result result_;

  Player& player_;
  Plug& plug_;

 public:
  PlugAttack(Player& player, Plug& plug, const Result& result)
      : result_(result), player_(player), plug_(plug) {}

  void trigger() {
    // if plug is not dead and has a weapon, he can attack
    if (!(plug_.healthBar().dead()) &&
        plug_.weapon().type != weapon::Type::noWeapon) {
      attack(&player_, plug_.weapon());

      action::writeResult(data::Action::resultPlugAttack(
          plug_.name(), plug_.weapon().nb_damage));
    }
  }
};
}  // namespace action

#endif