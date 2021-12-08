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
  Player& player_;
  const Options& options_;

  void endOfLevel() const;

 public:
  explicit Level(Player& player, const Options& options);
  virtual void startLevel() = 0;
  virtual ~Level() = default;
};

#endif