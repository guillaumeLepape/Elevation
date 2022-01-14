/*!
 * \file StartGame.cpp
 */

#include "StartGame.h"

#include "Level.h"
#include "Options.h"
#include "Player.h"

namespace action {
StartGame::StartGame(const Statement& statement, const utils::Options& options)
    : statement_{statement},
      options_{options},
      player_{"Joueur", utils::id::generate(), 0} {}

StartGame::StartGame(const Statement& statement, const utils::Options& options,
                     entity::Player&& player)
    : statement_{statement},
      options_{options},
      player_{std::forward<decltype(player)>(player)} {}

void StartGame::trigger() {
  std::array<Level, NB_LEVEL> levels = {Introduction{player_},
                                        Level1{player_},
                                        Level2{player_},
                                        Level3{player_},
                                        Level4{player_},
                                        Level5{player_, options_},
                                        Level6{player_},
                                        Level7{player_, options_},
                                        Level8{player_},
                                        Level9{player_, options_},
                                        Level10{player_, options_},
                                        Outro{player_}};

  for (std::size_t i = player_.nbLevelSuceeded(); i < NB_LEVEL; i++) {
    std::visit([](auto& level) { level.start(); }, levels[i]);
  }
}
}  // namespace action