#ifndef LEVEL_8_H
#define LEVEL_8_H

#include "Player.h"

class Level8 {
 private:
  entity::Player& player_;

 public:
  Level8(entity::Player& player) : player_{player} {}

  Level8(const Level8&) = delete;
  Level8(Level8&&) = default;

  Level8& operator=(const Level8&) = delete;
  Level8& operator=(Level8&&) = default;

  ~Level8() = default;

  void start();
};

#endif