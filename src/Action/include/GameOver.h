#ifndef GAME_OVER_H
#define GAME_OVER_H

/*!
 * \file GameOver.h
 */

#include <iostream>

#include "NameType.h"

class GameOver {
 private:
  ActionWriter actionWriter_;

 public:
  explicit GameOver(const Result& result) : actionWriter_("", result.get()) {}

  void triggerAction() {
    actionWriter_.writeResult();
    std::cout << "\n";
    exit(0);
  }
};

#endif