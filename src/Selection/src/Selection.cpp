/*!
 * \file Selection.cpp
 */

#include "Selection.h"

#include <limits>

#include "Pause.h"

int Select::select(const std::string& title,
                   const std::vector<std::string>& statements) {
  Selection::write(title, statements);

  long unsigned int choice = 0;

  while (!(std::cin >> choice) || (choice > statements.size() || choice < 1)) {
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

    Selection::write(title, statements);
  }

  return choice - 1;
}