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
    : statement_(statement),
      resultsData_(new ResultsData()),
      options_(options) {}

void LoadGame::triggerAction() {
  const auto& results = resultsData_->results();

  if (results.size() == 0) {
    std::cout << "\n " << Term::color(Term::bg::red)
              << Term::color(Term::style::bold)
              << "Aucune partie ne peut etre chargé."
              << Term::color(Term::bg::reset)
              << Term::color(Term::style::reset);

    std::cout << "\n";
  } else {
    std::vector<StartGame*> actions;
    for (auto r = results.cbegin(); r != results.cend(); r++) {
      actions.push_back(
          new StartGame(data::Menu::statementChooseLoadedGame(
                            (*r)->name(), (*r)->nbLevelSuceeded()),
                        options_, *r, resultsData_.get()));
    }

    std::vector<std::string> statements;
    std::transform(actions.cbegin(), actions.cend(),
                   std::back_inserter(statements),
                   [](const auto action) { return action->statement(); });
    auto result = Select::select(data::Menu::titleLoadGameMenu, statements);
    actions[result]->triggerAction();
  }
}