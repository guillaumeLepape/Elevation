#ifndef LEVEL_2_H
#define LEVEL_2_H

/*!
 * \file Level2.h
 */

#include "Level.h"

class Level2 : public Level {
 public:
  explicit Level2(entity::Player& player, const utils::Options& options)
      : Level(player, options) {}
  void startLevel() override;
  ~Level2() override = default;
};

#endif