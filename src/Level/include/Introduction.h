#ifndef INTRODUCTION_H
#define INTRODUCTION_H

/*!
 * \file Introduction.h
 */

#include "Level.h"

class Introduction : public Level {
 public:
  explicit Introduction(Player* const player, ResultsData* const resultsData,
                        const Options& options)
      : Level(player, resultsData, options) {}

  void startLevel() override;
  ~Introduction() override = default;
};

#endif