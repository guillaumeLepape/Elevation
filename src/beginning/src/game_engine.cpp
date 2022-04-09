#include "game_engine.h"

#include "introduction.h"
#include "level1.h"
#include "level10.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "level5.h"
#include "level6.h"
#include "level7.h"
#include "level8.h"
#include "level9.h"
#include "level_utils.h"
#include "outro.h"
#include "player.h"
#include "results.h"

namespace game_engine {
void launch(const utils::Options& options, const std::string& game_id) {
  entity::Player player = entity::make_player_from_game_id(game_id);

  auto introduction = [&player]() { Introduction{player}.start(); };
  auto level1 = [&player]() { Level1{player}.start(); };
  auto level2 = [&player]() { Level2{player}.start(); };
  auto level3 = [&player]() { Level3{player}.start(); };
  auto level4 = [&player]() { Level4{player}.start(); };
  auto level5 = [&player, &options]() { Level5{player, options}.start(); };
  auto level6 = [&player]() { Level6{player}.start(); };
  auto level7 = [&player, &options]() { Level7{player, options}.start(); };
  auto level8 = [&player]() { Level8{player}.start(); };
  auto level9 = [&player, &options]() { Level9{player, options}.start(); };
  auto level10 = [&player, &options]() { Level10{player, options}.start(); };
  auto outro = [&player]() { Outro{player}.start(); };

  using level =
      std::variant<decltype(introduction), decltype(level1), decltype(level2),
                   decltype(level3), decltype(level4), decltype(level5),
                   decltype(level6), decltype(level7), decltype(level8),
                   decltype(level9), decltype(level10), decltype(outro)>;

  static constexpr std::size_t nb_level = std::variant_size_v<level>;

  std::array<level, nb_level> levels = {introduction, level1, level2,  level3,
                                        level4,       level5, level6,  level7,
                                        level8,       level9, level10, outro};

  for (std::size_t i = player.nbLevelSuceeded(); i < nb_level; i++) {
    std::visit([](auto& l) { l(); }, levels[i]);
    player.nextLevel();
    data::save(game_id, player);
    if (i != nb_level) endoflevel();
  }
}
}  // namespace game_engine
