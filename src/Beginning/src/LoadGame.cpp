/*!
 * \file LoadGame.cpp
 */

#include "LoadGame.h"

#include <cpp-terminal/terminal.h>

#include "Languages.h"
#include "Options.h"
#include "Results.h"
#include "Selection.h"
#include "StartGame.h"

namespace action {
LoadGame::LoadGame(const Statement& statement, const Options& options)
    : statement_(statement), options_(options) {}

void LoadGame::trigger() {
  auto results = data::read_results("results", "results");

  if (results.data.size() == 0) {
    std::cout << "\n " << Term::color(Term::bg::red)
              << Term::color(Term::style::bold)
              << "Aucune partie ne peut etre chargé."
              << Term::color(Term::bg::reset)
              << Term::color(Term::style::reset);

    std::cout << "\n";
  } else {
    std::vector<std::string> statements;
    std::transform(std::cbegin(results.data), std::cend(results.data),
                   std::back_inserter(statements), [](const auto& resultData) {
                     return data::Menu::statementChooseLoadedGame(
                                resultData.pseudo(),
                                resultData.nbLevelSuceeded())
                         .get();
                   });
    auto result = Selection::select(data::Menu::titleLoadGameMenu, statements);

    StartGame startGame(Statement(statements[result]), options_,
                        std::move(results.data[result]));

    startGame.trigger();
  }
}
}  // namespace action