/*!
 * \file WriteResults.cpp
 */

#include "WriteResults.h"

#include <iostream>

#include "Player.h"

namespace action {
WriteResults::WriteResults(entity::Player& player, data::Results& results,
                           const Statement&, const Result& result)
    : result_{result}, player_{player}, results_{results} {}

void WriteResults::trigger() {
  data::add(results_, std::move(player_));
  data::write(results_, "results", "results");

  action::writeResult(result_);
  std::cout << "\n";
}
}  // namespace action