#ifndef REGENERATE_ALL_LIFE
#define REGENERATE_ALL_LIFE

/*!
 * \file RegenerateAllLife.h
 */

#include <iostream>

#include "NameType.h"

namespace action {
class RegenerateAllLife {
 private:
  Result result_;

  Player& player_;

 public:
  RegenerateAllLife(Player& player, const Result& result)
      : result_(result), player_(player) {}

  void trigger() {
    // if player is full life or dead, do nothing, else regenerate him
    if (!(player_.healthBar().fullLife()) && !(player_.healthBar().dead())) {
      action::writeResult(data::Action::resultRegeneration(
          player_.healthBar().missingLifePoints()));
      player_.healthBar().increaseLifePoints(
          player_.healthBar().missingLifePoints());
    }
  }
};
}  // namespace action

#endif
