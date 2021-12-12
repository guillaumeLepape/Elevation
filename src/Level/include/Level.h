#ifndef LEVEL_H
#define LEVEL_H

/*!
 * \file Level.h
 */

#include "Options.h"
#include "Player.h"
#include "Results.h"

class Level {
 protected:
  entity::Player& player_;
  const utils::Options& options_;

  void endOfLevel() const;

 public:
  explicit Level(entity::Player& player, const utils::Options& options);
  virtual void startLevel() = 0;
  virtual ~Level() = default;
};

#endif