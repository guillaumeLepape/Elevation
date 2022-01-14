#ifndef SELECTION_H
#define SELECTION_H

#include <vector>

#include "SelectionWriter.h"

namespace selection {
template <utils::Printable printable>
std::size_t select(const Title& title,
                   const std::vector<printable>& statements) {
  selection::write(title, statements);

  std::size_t choice = 0;

  while (not(std::cin >> choice) or
         (choice > std::size(statements) or choice < 1)) {
    if (std::size(statements) != 1) {
      std::cout << Term::color(Term::fg::red) << Term::color(Term::style::bold)
                << "Selection invalide - Entrez un nombre compris entre 1 et "
                << std::size(statements) << " !" << Term::color(Term::fg::reset)
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

template <utils::Printable... printable>
std::size_t select(const Title& title, const printable&... statements) {
  selection::write(title, statements...);

  std::size_t choice = 0;

  while (not(std::cin >> choice) or
         (choice > sizeof...(statements) or choice < 1)) {
    if constexpr (sizeof...(statements) != 1) {
      std::cout << Term::color(Term::fg::red) << Term::color(Term::style::bold)
                << "Selection invalide - Entrez un nombre compris entre 1 et "
                << sizeof...(statements) << " !" << Term::color(Term::fg::reset)
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

    selection::write(title, statements...);
  }

  return choice - 1;
}

template <typename T>
concept bool Action = requires(T& action) {
  { action.statement() }
  ->const std::string&;
  { action.trigger() }
  ->void;
};

template <Action... Args>
std::size_t select(const Title& title, Args&... actions) {
  auto result = selection::select(title, actions.statement()...);

  std::size_t index = 0;
  ((index++ == result ? actions.trigger() : []() {}()), ...);
  return result;
}

template <Action Arg>
std::size_t select(const Title& title, std::vector<Arg>& actions) {
  std::vector<std::string> statements;
  std::transform(std::cbegin(actions), std::cend(actions),
                 std::back_inserter(statements),
                 [](const auto& action) { return action.statement(); });
  auto result = selection::select(title, statements);
  actions[result].trigger();
  return result;
}
}  // namespace selection

#endif