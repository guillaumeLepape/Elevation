#ifndef LEVEL_9_H
#define LEVEL_9_H

#include "Options.h"
#include "Player.h"

class Level9 {
 private:
  entity::Player& player_;
  const utils::Options& options_;

 public:
  Level9(entity::Player& player, const utils::Options& options)
      : player_{player}, options_{options} {}

  Level9(const Level9&) = delete;
  Level9(Level9&&) = default;

  Level9& operator=(const Level9&) = delete;
  Level9& operator=(Level9&&) = default;

  ~Level9() = default;

  void start();
};

#endif