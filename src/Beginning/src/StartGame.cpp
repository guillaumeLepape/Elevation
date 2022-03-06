#include "StartGame.h"

#include "GameEngine.h"
#include "Level.h"
#include "Options.h"

namespace action {
StartGame::StartGame(const Statement& statement, const utils::Options& options)
    : statement_{statement}, options_{options} {}

void StartGame::trigger() {
  const unsigned game_id = utils::id::generate();
  game_engine::launch(options_, game_id);
}
}  // namespace action