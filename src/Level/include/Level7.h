#ifndef LEVEL_7_H
#define LEVEL_7_H

/*!
 * \file "Level7.h"
 */

#include "Level.h"

class Level7 : public Level {
 public:
  Level7(Player* const player, ResultsData* const resultsData,
         const Options& options)
      : Level(player, resultsData, options) {}

  void startLevel() override;

  ~Level7() override = default;
};

#endif