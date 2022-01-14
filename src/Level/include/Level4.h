#ifndef LEVEL_4_H
#define LEVEL_4_H

/*!
 * \file Level4.h
 */

#include "Player.h"

class Level4 {
 private:
  entity::Player& player_;

 public:
  Level4(entity::Player& player) : player_{player} {}

  Level4(const Level4&) = delete;
  Level4(Level4&&) = default;

  Level4& operator=(const Level4&) = delete;
  Level4& operator=(Level4&&) = default;

  ~Level4() = default;

  void start();
};

#endif