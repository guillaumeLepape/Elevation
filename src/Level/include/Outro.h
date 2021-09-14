#ifndef OUTRO_H
#define OUTRO_H

/*!
 * \file Outro.h
 */

#include "Level.h"

class Outro : public Level {
 public:
  Outro(Player& player, ResultsData& resultsData, const Options& options)
      : Level(player, resultsData, options) {}

  void startLevel() override;

  ~Outro() override = default;
};

#endif