#include "ActionWriter.h"

#include <fmt/color.h>

#include "Pause.h"

namespace action {
void writeStatement(const Statement& statement) {
  fmt::print("\n ");
  fmt::print(
      fg(fmt::color::black) | bg(fmt::color::yellow) | fmt::emphasis::bold,
      statement.get());
  fmt::print(" : ");
}
void writeResult(const Result& result) {
  utils::pause();
  fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold, "\n {}",
             result.get());
}
}  // namespace action