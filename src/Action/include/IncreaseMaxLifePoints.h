#ifndef INCREASE_MAX_LIFE_POINTS_H
#define INCREASE_MAX_LIFE_POINTS_H

/*!
 * \file IncreaseMaxLifePoints.h
 */

#include "NameType.h"

class IncreaseMaxLifePoints {
 private:
  ActionWriter actionWriter_;

  Player* const player_;
  int maxLifePointsIncreasing_;

 public:
  IncreaseMaxLifePoints(Player* const player, int maxLifePointsIncreasing,
                        const Result& result)
      : actionWriter_("", result.get()),
        player_(player),
        maxLifePointsIncreasing_(maxLifePointsIncreasing) {}

  void triggerAction() {
    player_->increaseMaxLifePoints(maxLifePointsIncreasing_);
    actionWriter_.writeResult();
  }
};

#endif