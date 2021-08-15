/*!
 * \file StartGame.cpp
 */

#include "StartGame.h"

#include "LevelFactory.h"
#include "Options.h"
#include "Player.h"

StartGame::StartGame(const std::string& statement, const std::string& result,
                     const Options& options, Player* const player,
                     ResultsData* const resultsData)
    : Action(statement, result),
      player_(player),
      resultsData_(resultsData),
      options_(options) {}

void StartGame::triggerAction() {
  int i = 0;
  for (i = player_->nbLevelSuceeded(); i < NB_LEVEL; i++) {
    std::unique_ptr<Level> level =
        LevelFactory::newLevel(player_.get(), resultsData_.get(), options_, i);

    level->startLevel();
  }
}
