#ifndef LEVEL_3_H
#define LEVEL_3_H

/*!
 * \file Level3.h
 */

#include "Level.h"

class Level3 : public Level {
 public:
  explicit Level3(entity::Player& player, const utils::Options& options)
      : Level(player, options) {}
  void startLevel() override;
  ~Level3() override = default;
};

#endif