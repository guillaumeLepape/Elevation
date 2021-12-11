/*!
 * \file SelectionWriter.cpp
 */

#include "SelectionWriter.h"

#include "Pause.h"
#include "UtilsWriter.h"

namespace Selection {
void write(const Title& title, const std::vector<std::string>& statements) {
  utils::pause();

  std::cout << "\n " << Term::color(Term::fg::black)
            << Term::color(Term::bg::green) << Term::color(Term::style::bold)
            << title.get() << Term::color(Term::fg::reset)
            << Term::color(Term::bg::reset) << Term::color(Term::style::reset);

  utils::writeSeparators();

  for (long unsigned int i = 0; i < statements.size(); i++) {
    std::cout << "\n " << std::to_string(i + 1) << "- "
              << Term::color(Term::fg::yellow) << Term::color(Term::style::bold)
              << statements[i] << Term::color(Term::fg::reset)
              << Term::color(Term::style::reset);
  }

  if (statements.size() != 1) {
    std::cout << "\n " << Term::color(Term::fg::black)
              << Term::color(Term::bg::yellow) << Term::color(Term::style::bold)
              << "Entrez un chiffre entre " << 1 << "-" << statements.size()
              << Term::color(Term::fg::reset) << Term::color(Term::bg::reset)
              << Term::color(Term::style::reset) << " : ";
  } else {
    std::cout << "\n " << Term::color(Term::fg::black)
              << Term::color(Term::bg::yellow) << Term::color(Term::style::bold)
              << "Entrez un chiffre égale à 1" << Term::color(Term::fg::reset)
              << Term::color(Term::bg::reset) << Term::color(Term::style::reset)
              << " : ";
  }
}
}  // namespace Selection
