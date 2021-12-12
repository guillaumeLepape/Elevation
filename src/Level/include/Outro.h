#ifndef OUTRO_H
#define OUTRO_H

/*!
 * \file Outro.h
 */

#include "Level.h"

class Outro : public Level {
 public:
  Outro(entity::Player& player, const utils::Options& options)
      : Level(player, options) {}

  void startLevel() override;

  ~Outro() override = default;
};

#endif