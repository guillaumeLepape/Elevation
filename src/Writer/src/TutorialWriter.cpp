#include "TutorialWriter.h"

#include <fmt/color.h>

#include <algorithm>
#include <iostream>

#include "Pause.h"
#include "UtilsWriter.h"

namespace Tutorial {
void write(const Title& title,
           const std::vector<std::string>& tutorialStatement) {
  utils::pause();

  fmt::print("\n ");
  fmt::print(bg(fmt::color::magenta) | fmt::emphasis::bold, title.get());

  utils::writeSeparators();

  std::for_each(std::cbegin(tutorialStatement), std::cend(tutorialStatement),
                [](const auto& statement) {
                  utils::pause();

                  fmt::print(fg(fmt::color::magenta) | fmt::emphasis::bold,
                             "\n {}", statement);
                });

  std::cout << "\n";
}
}  // namespace Tutorial