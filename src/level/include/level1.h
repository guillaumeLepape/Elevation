#ifndef LEVEL_1_H
#define LEVEL_1_H

#include "player.h"

class Level1 {
 private:
  entity::Player& player_;

 public:
  Level1(entity::Player& player) : player_{player} {}

  Level1(const Level1&) = delete;
  Level1(Level1&&) = default;

  Level1& operator=(const Level1&) = delete;
  Level1& operator=(Level1&&) = default;

  ~Level1() = default;

  void start();
};

#endif