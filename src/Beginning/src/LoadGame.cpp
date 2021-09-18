/*!
 * \file LoadGame.cpp
 */

#include "LoadGame.h"

#include <cpp-terminal/terminal.h>

#include "Languages.h"
#include "Options.h"
#include "ResultsData.h"
#include "Selection.h"
#include "StartGame.h"

LoadGame::LoadGame(const Statement& statement, const Options& options)
    : statement_(statement), resultsData_(ResultsData()), options_(options) {}

void LoadGame::triggerAction() {
  auto& results = resultsData_.results();

  if (results.size() == 0) {
    std::cout << "\n " << Term::color(Term::bg::red)
              << Term::color(Term::style::bold)
              << "Aucune partie ne peut etre chargé."
              << Term::color(Term::bg::reset)
              << Term::color(Term::style::reset);

    std::cout << "\n";
  } else {
    std::vector<std::string> statements;
    std::transform(std::cbegin(results), std::cend(results),
                   std::back_inserter(statements), [](const auto& resultData) {
                     return data::Menu::statementChooseLoadedGame(
                                resultData.name(), resultData.nbLevelSuceeded())
                         .get();
                   });
    auto result = Selection::select(data::Menu::titleLoadGameMenu, statements);

    StartGame startGame(Statement(statements[result]), options_, result,
                        std::move(resultsData_));

    startGame.triggerAction();
  }
}