#include "game_engine.h"

#include "level.h"
#include "level_utils.h"
#include "player.h"
#include "results.h"

namespace game_engine {
void launch(const utils::Options& options, const std::string& game_id) {
  entity::Player player = entity::make_player_from_game_id(game_id);

  std::array<Level, NB_LEVEL> levels = {
      Introduction{player},     Level1{player},
      Level2{player},           Level3{player},
      Level4{player},           Level5{player, options},
      Level6{player},           Level7{player, options},
      Level8{player},           Level9{player, options},
      Level10{player, options}, Outro{player}};

  for (std::size_t i = player.nbLevelSuceeded(); i < NB_LEVEL; i++) {
    std::visit([](auto& level) { level.start(); }, levels[i]);
    player.nextLevel();
    data::save(game_id, player);
    if (i != NB_LEVEL) endoflevel();
  }
}
}  // namespace game_engine
