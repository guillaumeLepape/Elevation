/*!
 * \file TutorialWriter.cpp
 */

#include "TutorialWriter.h"

#include <cpp-terminal/terminal.h>

#include <iostream>

#include "Pause.h"

namespace Tutorial {
void write(const Title& title,
           const std::vector<std::string>& tutorialStatement) {
  Pause::pause();

  std::cout << "\n " << Term::color(Term::bg::magenta)
            << Term::color(Term::style::bold) << title.get()
            << Term::color(Term::bg::reset) << Term::color(Term::style::reset);

  std::cout << "\n"
            << Term::color(Term::fg::black) << Term::color(Term::style::bold)
            << "========" << Term::color(Term::fg::reset)
            << Term::color(Term::style::reset);

  for (long unsigned int i = 0; i < tutorialStatement.size(); i++) {
    Pause::pause();

    std::cout << "\n " << Term::color(Term::fg::magenta)
              << Term::color(Term::style::bold) << tutorialStatement[i]
              << Term::color(Term::fg::reset)
              << Term::color(Term::style::reset);
  }

  std::cout << "\n";
}
}  // namespace Tutorial