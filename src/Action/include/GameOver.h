#ifndef GAME_OVER_H
#define GAME_OVER_H

/*!
 * \file GameOver.h
 */

#include <iostream>

#include "ActionWriter.h"
#include "NameType.h"

namespace action {
class GameOver {
 private:
  Result result_;

 public:
  explicit GameOver(const Result& result) : result_(result) {}

  void trigger() {
    action::writeResult(result_);
    std::cout << "\n";
    exit(0);
  }
};
}  // namespace action

#endif