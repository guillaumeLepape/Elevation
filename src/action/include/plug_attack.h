#pragma once

#include "concept.h"

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

      result::write(data::action::resultPlugAttack(plug_.name(),
                                                   plug_.weapon().nb_damage));
    }
  }
};

namespace plug_attack {
void trigger(entity::Player& player, entity::Plug& plug) {
  PlugAttack plug_attack{player, plug};
  plug_attack.trigger();
}
}  // namespace plug_attack
}  // namespace action
