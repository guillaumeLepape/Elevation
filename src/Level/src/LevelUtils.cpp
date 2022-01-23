#include "LevelUtils.h"

#include "Languages.h"
#include "Nothing.h"
#include "SaveAndQuit.h"
#include "Selection.h"
#include "WriteResults.h"

void endoflevel(entity::Player& player) {
  player.nextLevel();

  auto results = data::read_results("results", "results");

  action::WriteResults writeResults{player, results,
                                    data::Menu::statementSaveAndQuit,
                                    data::Menu::resultSaveAndQuit};
  writeResults.trigger();

  action::Nothing continueAction{data::Menu::statementContinue};
  action::SaveAndQuit quit{data::Menu::statementQuit, data::Menu::resultQuit};

  selection::select(data::Menu::titleContinueMenu, continueAction, quit);
}