#ifndef PLUG_ATTACK_H
#define PLUG_ATTACK_H

#include "Concept.h"

namespace action {
class PlugAttack {
 private:
  entity::Player& player_;
  entity::Plug& plug_;

 public:
  PlugAttack(entity::Player& player, entity::Plug& plug)
      : player_{player}, plug_{plug} {}

  void trigger() {
    // if plug is not dead and has a weapon, he can attack
    if (plug_.healthBar().alive() and
        plug_.weapon().type != weapon::Type::noWeapon) {
      entity::attack(player_, plug_.weapon());

      result::write(data::Action::resultPlugAttack(plug_.name(),
                                                   plug_.weapon().nb_damage));
    }
  }
};
}  // namespace action

#endif