#ifndef LEVEL_8_H
#define LEVEL_8_H

/*!
 * \file "Level8.h"
 */

#include "Level.h"

class Level8 : public Level {
 public:
  Level8(entity::Player& player, const utils::Options& options)
      : Level(player, options) {}

  void startLevel() override;

  ~Level8() override = default;
};

#endif