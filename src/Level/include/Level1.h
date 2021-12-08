#ifndef LEVEL_1_H
#define LEVEL_1_H

/*!
 * \file Level1.h
 */

#include "Level.h"

class Level1 : public Level {
 public:
  explicit Level1(Player& player, const Options& options)
      : Level(player, options) {}
  void startLevel() override;
  ~Level1() override = default;
};

#endif