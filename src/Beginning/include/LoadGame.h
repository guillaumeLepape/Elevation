#ifndef LOAD_GAME_H
#define LOAD_GAME_H

/*!
 * \file LoadGame.h
 */

#include <memory>

#include "Action.h"

// forward declaration of Options class
class Options;
class ResultsData;

class LoadGame : public Action {
 private:
  std::unique_ptr<ResultsData> resultsData_;
  const Options& options_;

 public:
  LoadGame(const std::string& statement, const std::string& result,
           const Options& options);

  void triggerAction() override;
};

#endif