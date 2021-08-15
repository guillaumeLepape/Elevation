#ifndef WRITE_RESULTS_H
#define WRITE_RESULTS_H

/*!
 * \file WriteResults.h
 */

#include "Action.h"

class Player;
class ResultsData;

class WriteResults : public Action {
 private:
  Player* const player_;
  ResultsData* const resultsData_;

 public:
  WriteResults(Player* const player, ResultsData* const resultsData,
               const std::string& statement, const std::string& result);

  void triggerAction() override;
};

#endif