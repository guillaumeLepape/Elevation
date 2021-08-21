#ifndef LEVEL_1_H
#define LEVEL_1_H

/*!
 * \file Level1.h
 */

#include "Level.h"

class Level1 : public Level {
 public:
  explicit Level1(Player* const player, ResultsData* const resultsData,
                  const Options& options)
      : Level(player, resultsData, options) {}
  void startLevel() override;
  ~Level1() override = default;
};

#endif