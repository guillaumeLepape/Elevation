#ifndef GAME_OVER_H
#define GAME_OVER_H

/*!
 * \file GameOver.h
 */

#include "Action.h"

class GameOver : public Action {
 public:
  explicit GameOver(const std::string& statement, const std::string& result)
      : Action(statement, result) {}

  void triggerAction() override {
    actionWriter_.writeResult();
    std::cout << "\n";
    exit(0);
  }
};

#endif