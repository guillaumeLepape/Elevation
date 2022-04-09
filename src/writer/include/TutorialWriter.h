#ifndef TUTORIAL_WRITER_H
#define TUTORIAL_WRITER_H

#include <fmt/color.h>

#include <range/v3/algorithm/for_each.hpp>
#include <vector>

#include "Concept.h"
#include "Pause.h"
#include "UtilsWriter.h"

namespace tutorial {
template <utils::Printable T>
void write(T&& title, const std::vector<std::string>& tutorialStatement) {
  utils::pause();

  fmt::print("\n ");
  fmt::print(bg(fmt::color::magenta) | fmt::emphasis::bold, title);

  utils::writeSeparators();

  ranges::for_each(tutorialStatement, [](const auto& statement) {
    utils::pause();

    fmt::print(fg(fmt::color::magenta) | fmt::emphasis::bold, "\n {}",
               statement);
  });

  fmt::print("\n");
}
}  // namespace tutorial

#endif