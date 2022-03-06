#include "LoadGame.h"

#include <fmt/color.h>

#include "GameEngine.h"
#include "Languages.h"
#include "Options.h"
#include "Results.h"
#include "Selection.h"

namespace action {
LoadGame::LoadGame(const Statement& statement, const utils::Options& options)
    : statement_{statement}, options_{options} {}

void LoadGame::trigger() {
  auto load_game_statements = data::create_load_game_statements();

  if (load_game_statements.size() == 0) {
    fmt::print("\n ");
    fmt::print(bg(fmt::color::red) | fmt::emphasis::bold,
               "Aucune partie ne peut etre chargé.");
    fmt::print("\n");
  } else {
    std::vector<std::string> statements;
    std::transform(
        std::cbegin(load_game_statements), std::cend(load_game_statements),
        std::back_inserter(statements), [](const auto& result_data) {
          return data::Menu::statementChooseLoadedGame(std::get<1>(result_data),
                                                       std::get<2>(result_data))
              .get();
        });
    auto result = selection::select(data::Menu::titleLoadGameMenu, statements);

    const unsigned game_id = std::get<0>(load_game_statements[result]);

    game_engine::launch(options_, game_id);
  }
}
}  // namespace action