/*!
 * \file Level.cpp
 */

#include "Level.h"

#include "Languages.h"
#include "Nothing.h"
#include "Quit.h"
#include "Selection.h"
#include "WriteResults.h"

Level::Level(Player* const player, ResultsData* const resultsData,
             const Options& options)
    : player_(player), resultsData_(resultsData), options_(options) {}

void Level::endOfLevel() const {
  player_->nextLevel();

  WriteResults writeResults(player_, resultsData_,
                            data::Menu::statementSaveAndQuit,
                            data::Menu::resultSaveAndQuit);
  writeResults.triggerAction();

  std::unique_ptr<Nothing> continueAction(
      new Nothing(data::Menu::statementContinue, ""));
  std::unique_ptr<Quit> quit(
      new Quit(data::Menu::statementQuit, data::Menu::resultQuit));

  Selection::select({continueAction.get(), quit.get()},
                    data::Menu::titleContinueMenu);
}