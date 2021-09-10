#ifndef WRITE_RESULTS_H
#define WRITE_RESULTS_H

/*!
 * \file WriteResults.h
 */

#include "ActionWriter.h"
#include "NameType.h"

class Player;
class ResultsData;

class WriteResults {
 private:
  Result result_;

  Player* const player_;
  ResultsData* const resultsData_;

 public:
  WriteResults(Player* const player, ResultsData* const resultsData,
               const Statement& statement, const Result& result);

  void triggerAction();
};

#endif