/*!
 * \file Level.cpp
 */

#include "Level.h"

#include "Languages.h"
#include "Nothing.h"
#include "SaveAndQuit.h"
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
      new Nothing(data::Menu::statementContinue));
  std::unique_ptr<SaveAndQuit> quit(
      new SaveAndQuit(data::Menu::statementQuit, data::Menu::resultQuit));

  auto result =
      Select::select(data::Menu::titleContinueMenu,
                     {continueAction->statement(), quit->statement()});

  switch (result) {
    case 0:
      continueAction->triggerAction();
      break;
    case 1:
      quit->triggerAction();
      break;
  }
}