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

namespace action {
class StartGame {
 private:
  Statement statement_;
  const Options& options_;
  Player player_;

 public:
  StartGame(const Statement& statement, const Options& options);
  StartGame(const Statement& statement, const Options& options,
            Player&& player);

  StartGame(const StartGame& startGame) = delete;

  const std::string& statement() const { return statement_.get(); }

  void trigger();
};
}  // namespace action

#endif