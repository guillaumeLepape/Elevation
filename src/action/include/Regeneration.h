#ifndef REGENERATION_H
#define REGENERATION_H

#include "Player.h"

namespace action {
class Regeneration {
 private:
  entity::Player& player_;

 public:
  Regeneration(entity::Player& player) : player_{player} {}

  void trigger() {
    auto nbLifePointsRegeneration = 0;

    // if player is full life or dead, do nothing, else regenerate him
    if ((not player_.healthBar().fullLife()) and
        (not player_.healthBar().dead())) {
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
      result::write(data::action::resultRegeneration(
          player_.healthBar().nbLifePoints() - nbLifePoints_previous));
    }
  }
};
}  // namespace action

#endif