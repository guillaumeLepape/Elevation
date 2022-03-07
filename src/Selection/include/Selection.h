#ifndef SELECTION_H
#define SELECTION_H

#include <fmt/color.h>

#include <algorithm>
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
      fmt::print(
          fg(fmt::color::red) | fmt::emphasis::bold,
          "Selection invalide - Entrez un nombre compris entre 1 et {} !\n",
          std::size(statements));
    } else {
      fmt::print(fg(fmt::color::red) | fmt::emphasis::bold,
                 "Selection invalide - Entrez un nombre égale à 1 !\n");
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
      fmt::print(
          fg(fmt::color::red) | fmt::emphasis::bold,
          "Selection invalide - Entrez un nombre compris entre 1 et {} !\n",
          sizeof...(statements));
    } else {
      fmt::print(fg(fmt::color::red) | fmt::emphasis::bold,
                 "Selection invalide - Entrez un nombre égale à 1 !\n");
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
concept Action = requires(T& action) {
  { action.statement() }
  ->std::convertible_to<const std::string_view&>;
  { action.trigger() }
  ->std::same_as<void>;
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