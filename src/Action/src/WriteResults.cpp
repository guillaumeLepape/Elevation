/*!
 * \file WriteResults.cpp
 */

#include "WriteResults.h"

#include <iostream>

#include "Player.h"
#include "ResultsData.h"

WriteResults::WriteResults(Player* const player, ResultsData* const resultsData,
                           const Statement& statement, const Result& result)
    : result_(result), player_(player), resultsData_(resultsData) {}

void WriteResults::triggerAction() {
  resultsData_->addResult(player_);
  resultsData_->writeData();

  Action::writeResult(result_);
  std::cout << "\n";
}