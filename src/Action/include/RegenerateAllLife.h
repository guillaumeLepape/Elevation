#ifndef REGENERATE_ALL_LIFE
#define REGENERATE_ALL_LIFE

/*!
 * \file RegenerateAllLife.h
 */

#include <iostream>

#include "NameType.h"
class RegenerateAllLife {
 private:
  Result result_;

  Player& player_;

 public:
  RegenerateAllLife(Player& player, const Result& result)
      : result_(result), player_(player) {}

  void triggerAction() {
    // if player is full life or dead, do nothing, else regenerate him
    if (!(player_.fullLife()) && !(player_.dead())) {
      Action::writeResult(
          data::Action::resultRegeneration(player_.missingLifePoints()));
      player_.increaseLifePoints(player_.missingLifePoints());
    }
  }
};

#endif
