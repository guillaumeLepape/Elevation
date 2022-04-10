#ifndef REGENERATE_ALL_LIFE
#define REGENERATE_ALL_LIFE

#include "player.h"

namespace action {
class RegenerateAllLife {
 private:
  entity::Player& player_;

 public:
  RegenerateAllLife(entity::Player& player) : player_{player} {}

  void trigger() {
    // if player is full life or dead, do nothing, else regenerate him
    if ((not player_.healthBar().fullLife()) and
        (player_.healthBar().alive())) {
      result::write(data::action::resultRegeneration(
          player_.healthBar().missingLifePoints()));
      player_.healthBar().increaseLifePoints(
          player_.healthBar().missingLifePoints());
    }
  }
};

namespace regenerate_all_life {
void trigger(entity::Player& player) {
  RegenerateAllLife regenerate_all_life{player};
  regenerate_all_life.trigger();
}
}  // namespace regenerate_all_life
}  // namespace action

#endif
