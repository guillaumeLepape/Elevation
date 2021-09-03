/*!
 * \file WriteResults.cpp
 */

#include "WriteResults.h"

#include <iostream>

#include "Player.h"
#include "ResultsData.h"

WriteResults::WriteResults(Player* const player, ResultsData* const resultsData,
                           const Statement& statement, const Result& result)
    : actionWriter_(statement.get(), result.get()),
      player_(player),
      resultsData_(resultsData) {}

void WriteResults::triggerAction() {
  resultsData_->addResult(player_);
  resultsData_->writeData();

  actionWriter_.writeResult();
  std::cout << "\n";
}