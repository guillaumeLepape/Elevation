/*!
 * \file WriteResults.cpp
 */

#include "WriteResults.h"

#include <iostream>

#include "Player.h"

WriteResults::WriteResults(Player& player, data::Results& results,
                           const Statement&, const Result& result)
    : result_(result), player_(player), results_(results) {}

void WriteResults::triggerAction() {
  data::add(results_, std::move(player_));
  data::write(results_, "results", "results");

  Action::writeResult(result_);
  std::cout << "\n";
}