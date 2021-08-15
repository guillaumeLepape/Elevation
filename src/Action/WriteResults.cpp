/*!
 * \file WriteResults.cpp
 */

#include "WriteResults.h"

#include <iostream>

#include "Player.h"
#include "ResultsData.h"

WriteResults::WriteResults(Player* const player, ResultsData* const resultsData,
                           const std::string& statement,
                           const std::string& result)
    : Action(statement, result), player_(player), resultsData_(resultsData) {}

void WriteResults::triggerAction() {
  resultsData_->addResult(player_);
  resultsData_->writeData();

  actionWriter_.writeResult();
  std::cout << "\n";
}