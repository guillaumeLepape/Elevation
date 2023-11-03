#pragma once

#include <fmt/color.h>

#include <string>

#include "elevation/utils/concept.h"
#include "elevation/utils/pause.h"

namespace elevation::action {
namespace statement {
template <utils::Printable T>
void write(T&& statement) {
  fmt::print("\n ");
  fmt::print(
      fg(fmt::color::black) | bg(fmt::color::yellow) | fmt::emphasis::bold,
      statement);
  fmt::print(" : ");
}
}  // namespace statement

namespace result {
template <utils::Printable T>
void write(T&& result) {
  utils::pause();
  fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold, "\n {}", result);
}
}  // namespace result
}  // namespace elevation::action
