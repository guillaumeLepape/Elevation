#pragma once

#include "elevation/utils/concept.h"

namespace elevation::action {
template <utils::Printable U>
class IncreaseMaxLifePoints {
 private:
  U result_;

  entity::Player& player_;
  int maxLifePointsIncreasing_;

 public:
  IncreaseMaxLifePoints(entity::Player& player, int maxLifePointsIncreasing,
                        const U& result)
      : result_{result},
        player_{player},
        maxLifePointsIncreasing_{maxLifePointsIncreasing} {}

  void trigger() {
    player_.healthBar().increaseMaxLifePoints(maxLifePointsIncreasing_);
    action::result::write(result_);
  }
};
}  // namespace elevation::action
