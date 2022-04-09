#ifndef LEVEL_3_H
#define LEVEL_3_H

#include "Player.h"

class Level3 {
 private:
  entity::Player& player_;

 public:
  Level3(entity::Player& player) : player_{player} {}

  Level3(const Level3&) = delete;
  Level3(Level3&&) = default;

  Level3& operator=(const Level3&) = delete;
  Level3& operator=(Level3&&) = default;

  ~Level3() = default;

  void start();
};

#endif