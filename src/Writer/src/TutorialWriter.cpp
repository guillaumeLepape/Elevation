#include "TutorialWriter.h"

#include <fmt/color.h>

#include <algorithm>
#include <iostream>
#include <range/v3/algorithm/for_each.hpp>

#include "Pause.h"
#include "UtilsWriter.h"

namespace Tutorial {
void write(const Title& title,
           const std::vector<std::string>& tutorialStatement) {
  utils::pause();

  fmt::print("\n ");
  fmt::print(bg(fmt::color::magenta) | fmt::emphasis::bold, title.get());

  utils::writeSeparators();

  ranges::for_each(tutorialStatement, [](const auto& statement) {
    utils::pause();

    fmt::print(fg(fmt::color::magenta) | fmt::emphasis::bold, "\n {}",
               statement);
  });

  std::cout << "\n";
}
}  // namespace Tutorial