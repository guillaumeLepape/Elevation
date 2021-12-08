/*!
 * \file StartGame.cpp
 */

#include "StartGame.h"

#include "LevelFactory.h"
#include "Options.h"
#include "Player.h"

namespace action {
StartGame::StartGame(const Statement& statement, const Options& options)
    : statement_(statement),
      options_(options),
      indexResultData_(0),
      player_("Joueur", Id::generate(), 0) {}

StartGame::StartGame(const Statement& statement, const Options& options,
                     int indexResultData, Player&& player)
    : statement_(statement),
      options_(options),
      indexResultData_(indexResultData),
      player_(std::forward<decltype(player)>(player)) {}

void StartGame::trigger() {
  for (int i = player_.nbLevelSuceeded(); i < NB_LEVEL; i++) {
    std::unique_ptr<Level> level = LevelFactory::newLevel(player_, options_, i);
    level->startLevel();
  }
}
}  // namespace action