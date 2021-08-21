#ifndef LEVEL_8_H
#define LEVEL_8_H

/*!
 * \file "Level8.h"
 */

#include "Level.h"

class Level8 : public Level {
 public:
  Level8(Player* const player, ResultsData* const resultsData,
         const Options& options)
      : Level(player, resultsData, options) {}

  void startLevel() override;

  ~Level8() override = default;
};

#endif