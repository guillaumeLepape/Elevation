/*!
 * \file Selection.cpp
 */

#include "Selection.h"

#include <limits>

#include "Pause.h"

int Selection::select(const std::vector<Action*>& actions,
                      const std::string& title) {
  SelectionWriter selectionWriter(actions, title);
  selectionWriter.writeSelection();

  long unsigned int choice = 0;

  while (!(std::cin >> choice) || (choice > actions.size() || choice < 1)) {
    if (actions.size() != 1) {
      std::cout << Term::color(Term::fg::red) << Term::color(Term::style::bold)
                << "Selection invalide - Entrez un nombre compris entre 1 et "
                << actions.size() << " !" << Term::color(Term::fg::reset)
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

    selectionWriter.writeSelection();
  }

  actions[choice - 1]->triggerAction();

  return choice - 1;
}