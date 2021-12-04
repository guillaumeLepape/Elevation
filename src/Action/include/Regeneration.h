#ifndef REGENERATION_H
#define REGENERATION_H

/*!
 * \file Regeneration.h
 */

#include "NameType.h"

class Regeneration {
 private:
  Result result_;

  Player& player_;

 public:
  Regeneration(Player& player, const Result& result)
      : result_(result), player_(player) {}

  void triggerAction() {
    int nbLifePointsRegeneration = 0;

    // if player is full life or dead, do nothing, else regenerate him
    if (!(player_.healthBar().fullLife()) && !(player_.healthBar().dead())) {
      switch (player_.nbLevelSuceeded()) {
        case 0 ... 4:
          nbLifePointsRegeneration = 10;
          break;
        case 5 ... 6:
          nbLifePointsRegeneration = 20;
          break;
        case 7 ... 8:
          nbLifePointsRegeneration = 23;
          break;
        case 9:
          nbLifePointsRegeneration = 90;
          break;
        case 10:
          nbLifePointsRegeneration = -100;
          break;
        default:
          nbLifePointsRegeneration = 0;
          break;
      }

      int nbLifePoints_previous = player_.healthBar().nbLifePoints();

      player_.healthBar().increaseLifePoints(nbLifePointsRegeneration);
      Action::writeResult(data::Action::resultRegeneration(
          player_.healthBar().nbLifePoints() - nbLifePoints_previous));
    }
  }
};

#endif