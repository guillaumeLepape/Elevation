#ifndef INTRODUCTION_H
#define INTRODUCTION_H

/*!
 * \file Introduction.h
 */

#include "Level.h"

class Introduction : public Level {
 public:
  explicit Introduction(entity::Player& player, const utils::Options& options)
      : Level(player, options) {}

  void startLevel() override;
  ~Introduction() override = default;
};

#endif