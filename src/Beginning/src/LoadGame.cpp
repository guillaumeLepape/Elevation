#include "LoadGame.h"

#include <fmt/color.h>

#include "Languages.h"
#include "Options.h"
#include "Results.h"
#include "Selection.h"
#include "StartGame.h"

namespace action {
LoadGame::LoadGame(const Statement& statement, const utils::Options& options)
    : statement_{statement}, options_{options} {}

void LoadGame::trigger() {
  auto results = data::read_results("results", "results");

  if (results.data.size() == 0) {
    fmt::print("\n ");
    fmt::print(bg(fmt::color::red) | fmt::emphasis::bold,
               "Aucune partie ne peut etre chargé.");
    fmt::print("\n");
  } else {
    std::vector<std::string> statements;
    std::transform(std::cbegin(results.data), std::cend(results.data),
                   std::back_inserter(statements), [](const auto& resultData) {
                     return data::Menu::statementChooseLoadedGame(
                                resultData.pseudo(),
                                resultData.nbLevelSuceeded())
                         .get();
                   });
    auto result = selection::select(data::Menu::titleLoadGameMenu, statements);

    StartGame startGame{Statement{statements[result]}, options_,
                        std::move(results.data[result])};

    startGame.trigger();
  }
}
}  // namespace action