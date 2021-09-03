/*!
 * \file StartGame.cpp
 */

#include "StartGame.h"

#include "LevelFactory.h"
#include "Options.h"
#include "Player.h"

StartGame::StartGame(const Statement& statement, const Options& options,
                     Player* const player, ResultsData* const resultsData)
    : statement_(statement),
      player_(player),
      resultsData_(resultsData),
      options_(options) {}

void StartGame::triggerAction() {
  for (int i = player_->nbLevelSuceeded(); i < NB_LEVEL; i++) {
    std::unique_ptr<Level> level =
        LevelFactory::newLevel(player_.get(), resultsData_.get(), options_, i);

    level->startLevel();
  }
}
