/*!
 * \file StartGame.cpp
 */

#include "StartGame.h"

#include "LevelFactory.h"
#include "Options.h"
#include "Player.h"

namespace action {
StartGame::StartGame(const Statement& statement, const utils::Options& options)
    : statement_(statement),
      options_(options),
      player_("Joueur", Id::generate(), 0) {}

StartGame::StartGame(const Statement& statement, const utils::Options& options,
                     Player&& player)
    : statement_(statement),
      options_(options),
      player_(std::forward<decltype(player)>(player)) {}

void StartGame::trigger() {
  for (int i = player_.nbLevelSuceeded(); i < NB_LEVEL; i++) {
    std::unique_ptr<Level> level = LevelFactory::newLevel(player_, options_, i);
    level->startLevel();
  }
}
}  // namespace action