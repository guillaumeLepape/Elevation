#ifndef START_GAME_H
#define START_GAME_H

/*!
 * \file StartGame.h
 */

#include "Id.h"
#include "NameType.h"
#include "Player.h"
#include "ResultsData.h"

class Options;

class StartGame {
 private:
  Statement statement_;

  const std::unique_ptr<Player> player_;
  const std::unique_ptr<ResultsData> resultsData_;
  const Options& options_;

 public:
  StartGame(const Statement& statement, const Options& options,
            Player* const player = new Player("Joueur", Id::generateId(), 0),
            ResultsData* const resultsData = new ResultsData());

  StartGame(const StartGame& startGame) = delete;

  const std::string& statement() const { return statement_.get(); }

  void triggerAction();
};

#endif