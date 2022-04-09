#ifndef LEVEL_2_H
#define LEVEL_2_H

#include "Player.h"

class Level2 {
 private:
  entity::Player& player_;

 public:
  Level2(entity::Player& player) : player_{player} {}

  Level2(const Level2&) = delete;
  Level2(Level2&&) = default;

  Level2& operator=(const Level2&) = delete;
  Level2& operator=(Level2&&) = default;

  ~Level2() = default;

  void start();
};

#endif