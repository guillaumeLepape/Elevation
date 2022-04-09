#ifndef LEVEL_5_H
#define LEVEL_5_H

#include "options.h"
#include "player.h"

class Level5 {
 private:
  entity::Player& player_;
  const utils::Options& options_;

 public:
  Level5(entity::Player& player, const utils::Options& options)
      : player_{player}, options_{options} {}

  Level5(const Level5&) = delete;
  Level5(Level5&&) = default;

  Level5& operator=(const Level5&) = delete;
  Level5& operator=(Level5&&) = default;

  ~Level5() = default;

  void start();
};

#endif