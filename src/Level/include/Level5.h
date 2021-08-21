#ifndef LEVEL_5_H
#define LEVEL_5_H

/*!
 * \file Level5.h
 */

#include "Level.h"

class Level5 : public Level {
 public:
  explicit Level5(Player* const player, ResultsData* const resultsData,
                  const Options& options)
      : Level(player, resultsData, options) {}

  void startLevel() override;

  ~Level5() override = default;
};

#endif