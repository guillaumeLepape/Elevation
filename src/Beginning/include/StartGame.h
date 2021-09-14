#ifndef START_GAME_H
#define START_GAME_H

/*!
 * \file StartGame.h
 */

#include "Id.h"
#include "NameType.h"
#include "Options.h"
#include "Player.h"
#include "ResultsData.h"

class StartGame {
 private:
  Statement statement_;

  Player player_;
  ResultsData resultsData_;
  const Options& options_;

 public:
  StartGame(const Statement& statement, const Options& options,
            Player&& player = Player("Joueur", Id::generateId(), 0),
            ResultsData&& resultsData = ResultsData());

  StartGame(const StartGame& startGame) = delete;

  const std::string& statement() const { return statement_.get(); }

  void triggerAction();
};

#endif