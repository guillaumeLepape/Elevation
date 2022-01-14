#ifndef LEVEL_6_H
#define LEVEL_6_H

#include "Player.h"

class Level6 {
 private:
  entity::Player& player_;

 public:
  Level6(entity::Player& player) : player_{player} {}

  Level6(const Level6&) = delete;
  Level6(Level6&&) = default;

  Level6& operator=(const Level6&) = delete;
  Level6& operator=(Level6&&) = default;

  ~Level6() = default;

  void start();
};

#endif