#ifndef INCREASE_MAX_LIFE_POINTS_H
#define INCREASE_MAX_LIFE_POINTS_H

/*!
 * \file IncreaseMaxLifePoints.h
 */

#include "Action.h"

class IncreaseMaxLifePoints : public Action {
 private:
  Player* const player_;
  int maxLifePointsIncreasing_;

 public:
  IncreaseMaxLifePoints(Player* const player, int maxLifePointsIncreasing,
                        const std::string& statement, const std::string& result)
      : Action(statement, result),
        player_(player),
        maxLifePointsIncreasing_(maxLifePointsIncreasing) {}

  void triggerAction() override {
    player_->increaseMaxLifePoints(maxLifePointsIncreasing_);
    actionWriter_.writeResult();
  }
};

#endif