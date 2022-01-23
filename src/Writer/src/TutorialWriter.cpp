#include "TutorialWriter.h"

#include <cpp-terminal/terminal.h>

#include <iostream>

#include "Pause.h"
#include "UtilsWriter.h"

namespace Tutorial {
void write(const Title& title,
           const std::vector<std::string>& tutorialStatement) {
  utils::pause();

  std::cout << "\n " << Term::color(Term::bg::magenta)
            << Term::color(Term::style::bold) << title.get()
            << Term::color(Term::bg::reset) << Term::color(Term::style::reset);

  utils::writeSeparators();

  std::for_each(std::cbegin(tutorialStatement), std::cend(tutorialStatement),
                [](const auto& statement) {
                  utils::pause();

                  std::cout << "\n " << Term::color(Term::fg::magenta)
                            << Term::color(Term::style::bold) << statement
                            << Term::color(Term::fg::reset)
                            << Term::color(Term::style::reset);
                });

  std::cout << "\n";
}
}  // namespace Tutorial