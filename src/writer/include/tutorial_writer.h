#pragma once

#include <fmt/color.h>

#include <range/v3/algorithm/for_each.hpp>
#include <vector>

#include "concept.h"
#include "pause.h"
#include "utils_writer.h"

namespace tutorial {
template <utils::Printable T, typename U>
  requires utils::Printable<ranges::range_value_t<U>>
void write(T&& title, U&& tutorialStatement) {
  utils::pause();

  fmt::print("\n ");
  fmt::print(bg(fmt::color::magenta) | fmt::emphasis::bold,
             std::forward<T>(title));

  utils::writeSeparators();

  ranges::for_each(std::forward<U>(tutorialStatement),
                   [](const auto& statement) {
                     utils::pause();

                     fmt::print(fg(fmt::color::magenta) | fmt::emphasis::bold,
                                "\n {}", statement);
                   });

  fmt::print("\n");
}
}  // namespace tutorial
