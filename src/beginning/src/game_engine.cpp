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

  auto introduction = [&player]() { introduction::start(player); };
  auto level1 = [&player]() { level1::start(player); };
  auto level2 = [&player]() { level2::start(player); };
  auto level3 = [&player]() { level3::start(player); };
  auto level4 = [&player]() { level4::start(player); };
  auto level5 = [&player, &options]() { level5::start(player, options); };
  auto level6 = [&player]() { level6::start(player); };
  auto level7 = [&player, &options]() { level7::start(player, options); };
  auto level8 = [&player]() { level8::start(player); };
  auto level9 = [&player, &options]() { level9::start(player, options); };
  auto level10 = [&player, &options]() { level10::start(player, options); };
  auto outro = [&player]() { outro::start(player); };

  using Level =
      std::variant<decltype(introduction), decltype(level1), decltype(level2),
                   decltype(level3), decltype(level4), decltype(level5),
                   decltype(level6), decltype(level7), decltype(level8),
                   decltype(level9), decltype(level10), decltype(outro)>;

  static constexpr std::size_t NB_LEVEL = std::variant_size_v<Level>;

  std::array<Level, NB_LEVEL> levels = {introduction, level1, level2,  level3,
                                        level4,       level5, level6,  level7,
                                        level8,       level9, level10, outro};

  for (std::size_t i = player.nbLevelSuceeded(); i < NB_LEVEL; i++) {
    std::visit([](auto& level) { level(); }, levels[i]);
    player.nextLevel();
    data::save(game_id, player);
    if (i != NB_LEVEL - 1) utils::level::end();
  }
}
}  // namespace game_engine