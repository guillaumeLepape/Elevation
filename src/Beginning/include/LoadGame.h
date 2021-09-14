#ifndef LOAD_GAME_H
#define LOAD_GAME_H

/*!
 * \file LoadGame.h
 */

#include <memory>

#include "NameType.h"
#include "Options.h"
#include "ResultsData.h"

class LoadGame {
 private:
  const Statement& statement_;

  ResultsData resultsData_;
  const Options& options_;

 public:
  LoadGame(const Statement& statement, const Options& options);

  const std::string& statement() const { return statement_.get(); }

  void triggerAction();
};

#endif