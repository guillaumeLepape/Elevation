#ifndef START_GAME_H
#define START_GAME_H

/*!
 * \file StartGame.h
 */

#include "Id.h"
#include "NameType.h"
#include "Options.h"
#include "Player.h"
#include "Results.h"

class StartGame {
 private:
  Statement statement_;
  const Options& options_;

  std::size_t indexResultData_;
  Player player_;

 public:
  StartGame(const Statement& statement, const Options& options);
  StartGame(const Statement& statement, const Options& options,
            int indexResultData, Player&& player);

  StartGame(const StartGame& startGame) = delete;

  const std::string& statement() const { return statement_.get(); }

  void trigger();
};

#endif