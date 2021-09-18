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

  Player& player_;
  ResultsData& resultsData_;

 public:
  WriteResults(Player& player, ResultsData& resultsData,
               const Statement& statement, const Result& result);

  void triggerAction();
};

#endif