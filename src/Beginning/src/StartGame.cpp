/*!
 * \file StartGame.cpp
 */

#include "StartGame.h"

#include "LevelFactory.h"
#include "Options.h"
#include "Player.h"

StartGame::StartGame(const Statement& statement, const Options& options,
                     Player&& player, ResultsData&& resultsData)
    : statement_(statement),
      player_(std::move(player)),
      resultsData_(std::move(resultsData)),
      options_(options) {}

void StartGame::triggerAction() {
  for (int i = player_.nbLevelSuceeded(); i < NB_LEVEL; i++) {
    std::unique_ptr<Level> level =
        LevelFactory::newLevel(player_, resultsData_, options_, i);

    level->startLevel();
  }
}
