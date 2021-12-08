#ifndef WRITE_RESULTS_H
#define WRITE_RESULTS_H

/*!
 * \file WriteResults.h
 */

#include "ActionWriter.h"
#include "NameType.h"
#include "Player.h"
#include "Results.h"

class WriteResults {
 private:
  Result result_;

  Player& player_;
  data::Results& results_;

 public:
  WriteResults(Player& player, data::Results& results,
               const Statement& statement, const Result& result);

  void triggerAction();
};

#endif