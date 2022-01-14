#ifndef LEVEL_7_H
#define LEVEL_7_H

/*!
 * \file "Level7.h"
 */

#include "Options.h"
#include "Player.h"

class Level7 {
 private:
  entity::Player& player_;
  const utils::Options& options_;

 public:
  Level7(entity::Player& player, const utils::Options& options)
      : player_{player}, options_{options} {}

  Level7(const Level7&) = delete;
  Level7(Level7&&) = default;

  Level7& operator=(const Level7&) = delete;
  Level7& operator=(Level7&&) = default;

  ~Level7() = default;

  void start();
};

#endif