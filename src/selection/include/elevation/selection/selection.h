#pragma once

#include <fmt/color.h>

#include <algorithm>
#include <vector>

#include "elevation/writer/selection_writer.h"

namespace elevation::selection {
template <utils::Printable T, utils::Printable printable>
std::size_t select_from_statement(T&& title,
                                  const std::vector<printable>& statements) {
  selection::write(std::forward<T>(title), statements);

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

    selection::write(std::forward<T>(title), statements);
  }

  return choice - 1;
}

template <utils::Printable T, utils::Printable... Args>
std::size_t select_from_statement(T&& title, Args&&... statements) {
  selection::write(std::forward<T>(title), statements...);

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

    selection::write(std::forward<T>(title), statements...);
  }

  return choice - 1;
}

template <utils::Printable T, utils::Action... Args>
std::size_t select(T&& title, Args&&... actions) {
  auto result = selection::select_from_statement(std::forward<T>(title),
                                                 actions.statement()...);

  std::size_t index = 0;
  ((index++ == result ? actions.trigger() : []() {}()), ...);
  return result;
}

template <utils::Printable T, utils::Action Arg>
std::size_t select(T&& title, std::vector<Arg>& actions) {
  std::vector<std::string> statements;
  std::transform(std::cbegin(actions), std::cend(actions),
                 std::back_inserter(statements),
                 [](const auto& action) { return action.statement(); });
  auto result =
      selection::select_from_statement(std::forward<T>(title), statements);
  actions[result].trigger();
  return result;
}
}  // namespace elevation::selection
