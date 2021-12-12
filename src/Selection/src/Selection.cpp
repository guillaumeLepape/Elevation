/*!
 * \file Selection.cpp
 */

#include "Selection.h"

#include <limits>

#include "Pause.h"

namespace selection {
std::size_t select(const Title& title,
                   const std::vector<std::string>& statements) {
  selection::write(title, statements);

  std::size_t choice = 0;

  while (not(std::cin >> choice) or
         (choice > statements.size() or choice < 1)) {
    if (statements.size() != 1) {
      std::cout << Term::color(Term::fg::red) << Term::color(Term::style::bold)
                << "Selection invalide - Entrez un nombre compris entre 1 et "
                << statements.size() << " !" << Term::color(Term::fg::reset)
                << Term::color(Term::style::reset) << "\n";
    } else {
      std::cout << Term::color(Term::fg::red) << Term::color(Term::style::bold)
                << "Selection invalide - Entrez un nombre égale à 1 !"
                << Term::color(Term::fg::reset)
                << Term::color(Term::style::reset) << "\n";
    }
    // reset error flags
    std::cin.clear();

    // throw away garbage input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    selection::write(title, statements);
  }

  return choice - 1;
}
}  // namespace selection