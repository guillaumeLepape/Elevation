#ifndef LOAD_GAME_H
#define LOAD_GAME_H

/*!
 * \file LoadGame.h
 */

#include <memory>

#include "NameType.h"

// forward declaration of Options class
class Options;
class ResultsData;

class LoadGame {
 private:
  const Statement& statement_;

  std::unique_ptr<ResultsData> resultsData_;
  const Options& options_;

 public:
  LoadGame(const Statement& statement, const Options& options);

  const std::string& statement() const { return statement_.get(); }

  void triggerAction();
};

#endif