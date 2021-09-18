/*!
 * \file StartGame.cpp
 */

#include "StartGame.h"

#include "LevelFactory.h"
#include "Options.h"
#include "Player.h"

StartGame::StartGame(const Statement& statement, const Options& options)
    : statement_(statement),
      options_(options),
      indexResultData_(0),
      resultsData_(ResultsData(Player("Joueur", Id::generateId(), 0))),
      player_(resultsData_.results()[indexResultData_]) {}

StartGame::StartGame(const Statement& statement, const Options& options,
                     int indexResultData, ResultsData&& resultsData)
    : statement_(statement),
      options_(options),
      indexResultData_(indexResultData),
      resultsData_(std::move(resultsData)),
      player_(resultsData_.results()[indexResultData_]) {}

void StartGame::triggerAction() {
  for (int i = player_.nbLevelSuceeded(); i < NB_LEVEL; i++) {
    std::unique_ptr<Level> level =
        LevelFactory::newLevel(player_, resultsData_, options_, i);

    level->startLevel();
  }
}
