#ifndef INCREASE_MAX_LIFE_POINTS_H
#define INCREASE_MAX_LIFE_POINTS_H

/*!
 * \file IncreaseMaxLifePoints.h
 */

#include "NameType.h"

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

  void triggerAction() {
    player_.healthBar().increaseMaxLifePoints(maxLifePointsIncreasing_);
    Action::writeResult(result_);
  }
};

#endif