/*!
 * \file Level.cpp
 */

#include "Level.h"

#include "Languages.h"
#include "Nothing.h"
#include "SaveAndQuit.h"
#include "SelectionWrapper.h"
#include "WriteResults.h"

Level::Level(Player& player, const utils::Options& options)
    : player_(player), options_(options) {}

void Level::endOfLevel() const {
  player_.nextLevel();

  auto results = data::read_results("results", "results");

  action::WriteResults writeResults(player_, results,
                                    data::Menu::statementSaveAndQuit,
                                    data::Menu::resultSaveAndQuit);
  writeResults.trigger();

  action::Nothing continueAction(data::Menu::statementContinue);
  action::SaveAndQuit quit(data::Menu::statementQuit, data::Menu::resultQuit);

  selection::select(data::Menu::titleContinueMenu, continueAction, quit);
}