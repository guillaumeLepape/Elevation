#ifndef LEVEL_9_H
#define LEVEL_9_H

/*!
 * \file Level9.h
 */

#include "Level.h"

class Level9 : public Level {
 public:
  Level9(entity::Player& player, const utils::Options& options)
      : Level(player, options) {}

  void startLevel() override;

  ~Level9() override = default;
};

#endif