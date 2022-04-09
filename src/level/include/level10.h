#ifndef LEVEL_10_H
#define LEVEL_10_H

#include "options.h"
#include "player.h"

class Level10 {
 private:
  entity::Player& player_;
  const utils::Options& options_;

 public:
  Level10(entity::Player& player, const utils::Options& options)
      : player_{player}, options_{options} {}

  Level10(const Level10&) = delete;
  Level10(Level10&&) = default;

  Level10& operator=(const Level10&) = delete;
  Level10& operator=(Level10&&) = default;

  ~Level10() = default;

  void start();
};

#endif