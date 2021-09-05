#ifndef GAME_OVER_H
#define GAME_OVER_H

/*!
 * \file GameOver.h
 */

#include <iostream>

#include "ActionWriter.h"
#include "NameType.h"

class GameOver {
 private:
  const Result& result_;

 public:
  explicit GameOver(const Result& result) : result_(result) {}

  void triggerAction() {
    Action::writeResult(result_);
    std::cout << "\n";
    exit(0);
  }
};

#endif