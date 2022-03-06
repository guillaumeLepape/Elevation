#ifndef SELECTION_WRITER_H
#define SELECTION_WRITER_H

#include <fmt/color.h>

#include <string_view>
#include <vector>

#include "Concept.h"
#include "NameType.h"
#include "Pause.h"
#include "UtilsWriter.h"

namespace selection {

template <utils::Printable printable>
void write_statements(const std::vector<printable>& statements) {
  std::size_t index = 1;
  for (const auto& statement : statements) {
    fmt::print("\n {}- ", index++);
    fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold, statement);
  }
}

template <utils::Printable... printable>
void write_statements(const printable&... statements) {
  std::size_t index = 1;

  (
      [&index](const auto& statement) {
        fmt::print("\n {}- ", index++);
        fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold, statement);
      }(statements),
      ...);
}

template <utils::Printable printable>
void write(const Title& title, const std::vector<printable>& statements) {
  utils::pause();

  fmt::print("\n ");
  fmt::print(
      fg(fmt::color::black) | bg(fmt::color::green) | fmt::emphasis::bold,
      title.get());

  utils::writeSeparators();

  write_statements(statements);

  if (std::size(statements) != 1) {
    fmt::print("\n ");
    fmt::print(
        fg(fmt::color::black) | bg(fmt::color::yellow) | fmt::emphasis::bold,
        "Entrez un chiffre entre 1-{}", std::size(statements));
    fmt::print(" : ");
  } else {
    fmt::print("\n ");
    fmt::print(
        fg(fmt::color::black) | bg(fmt::color::yellow) | fmt::emphasis::bold,
        "Entrez un chiffre égale à 1");
    fmt::print(" : ");
  }
}

template <utils::Printable... printable>
void write(const Title& title, const printable&... statements) {
  utils::pause();

  fmt::print("\n ");
  fmt::print(
      fg(fmt::color::black) | bg(fmt::color::green) | fmt::emphasis::bold,
      title.get());

  utils::writeSeparators();

  write_statements(statements...);

  if constexpr (sizeof...(statements) != 1) {
    fmt::print("\n ");
    fmt::print(
        fg(fmt::color::black) | bg(fmt::color::yellow) | fmt::emphasis::bold,
        "Entrez un chiffre entre 1-{}", sizeof...(statements));
    fmt::print(" : ");
  } else {
    fmt::print("\n ");
    fmt::print(
        fg(fmt::color::black) | bg(fmt::color::yellow) | fmt::emphasis::bold,
        "Entrez un chiffre égale à 1");
    fmt::print(" : ");
  }
}
}  // namespace selection

#endif