#ifndef INCREASE_MAX_LIFE_POINTS_H
#define INCREASE_MAX_LIFE_POINTS_H

/*!
 * \file IncreaseMaxLifePoints.h
 */

#include "NameType.h"

namespace action {
class IncreaseMaxLifePoints {
 private:
  Result result_;

  Player& player_;
  int maxLifePointsIncreasing_;

 public:
  IncreaseMaxLifePoints(Player& player, int maxLifePointsIncreasing,
                        const Result& result)
      : result_(result),
        player_(player),
        maxLifePointsIncreasing_(maxLifePointsIncreasing) {}

  void trigger() {
    player_.healthBar().increaseMaxLifePoints(maxLifePointsIncreasing_);
    action::writeResult(result_);
  }
};
}  // namespace action

#endif