#pragma once

#include <fmt/color.h>

#include "elevation/beginning/game_engine.h"
#include "elevation/entity/results.h"
#include "elevation/selection/selection.h"
#include "elevation/utils/concept.h"
#include "elevation/utils/options.h"

namespace elevation::action {
template <utils::Printable T>
class LoadGame {
 private:
  const T& statement_;
  const utils::Options& options_;

 public:
  LoadGame(const T& statement, const utils::Options& options)
      : statement_{statement}, options_{options} {}

  LoadGame(const LoadGame&) = delete;
  LoadGame(LoadGame&&) noexcept = default;

  LoadGame& operator=(const LoadGame&) = delete;
  LoadGame& operator=(LoadGame&&) noexcept = default;

  ~LoadGame() noexcept = default;

  [[nodiscard]] const T& statement() const { return statement_; }

  void trigger() {
    auto load_game_statements = data::create_load_game_statements();

    if (load_game_statements.empty()) {
      fmt::print("\n ");
      fmt::print(bg(fmt::color::red) | fmt::emphasis::bold,
                 "Aucune partie ne peut etre chargé.");
      fmt::print("\n");
    } else {
      std::vector<std::string> statements;
      std::transform(
          std::cbegin(load_game_statements), std::cend(load_game_statements),
          std::back_inserter(statements), [](const auto& result_data) {
            return data::menu::statementChooseLoadedGame(
                std::get<1>(result_data), std::get<2>(result_data));
          });
      auto result = selection::select_from_statement(
          data::menu::titleLoadGameMenu, statements);

      const auto game_id = std::get<0>(load_game_statements[result]);

      game_engine::launch(options_, game_id);
    }
  }
};
}  // namespace elevation::action
