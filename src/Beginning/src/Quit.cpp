#include "Quit.h"

#include <iostream>

namespace action {
Quit::Quit(const Statement& statement, const Result& result)
    : statement_(statement), result_(result) {}

void Quit::trigger() {
  action::writeResult(result_);
  std::cout << "\n";
}
}  // namespace action