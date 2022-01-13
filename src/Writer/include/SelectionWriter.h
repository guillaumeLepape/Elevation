#ifndef SELECTION_WRITER_H
#define SELECTION_WRITER_H

/*!
 * \file SelectionWriter.h
 */

#include <string_view>
#include <vector>

#include "Concept.h"
#include "NameType.h"
#include "Pause.h"
#include "UtilsWriter.h"

namespace selection {
template <utils::Printable printable>
void write(const Title& title, const std::vector<printable>& statements) {
  utils::pause();

  std::cout << "\n " << Term::color(Term::fg::black)
            << Term::color(Term::bg::green) << Term::color(Term::style::bold)
            << title.get() << Term::color(Term::fg::reset)
            << Term::color(Term::bg::reset) << Term::color(Term::style::reset);

  utils::writeSeparators();

  {
    std::size_t index = 1;
    for (const auto& statement : statements) {
      std::cout << "\n " << index++ << "- " << Term::color(Term::fg::yellow)
                << Term::color(Term::style::bold) << statement
                << Term::color(Term::fg::reset)
                << Term::color(Term::style::reset);
    }
  }

  if (std::size(statements) != 1) {
    std::cout << "\n " << Term::color(Term::fg::black)
              << Term::color(Term::bg::yellow) << Term::color(Term::style::bold)
              << "Entrez un chiffre entre " << 1 << "-" << std::size(statements)
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

template <utils::Printable... printable>
void write(const Title& title, const printable&... statements) {
  utils::pause();

  std::cout << "\n " << Term::color(Term::fg::black)
            << Term::color(Term::bg::green) << Term::color(Term::style::bold)
            << title.get() << Term::color(Term::fg::reset)
            << Term::color(Term::bg::reset) << Term::color(Term::style::reset);

  utils::writeSeparators();

  {
    std::size_t index = 0;
    ((std::cout << "\n " << std::to_string(++index) << "- "
                << Term::color(Term::fg::yellow)
                << Term::color(Term::style::bold) << statements
                << Term::color(Term::fg::reset)
                << Term::color(Term::style::reset)),
     ...);
  }

  if constexpr (sizeof...(statements) != 1) {
    std::cout << "\n " << Term::color(Term::fg::black)
              << Term::color(Term::bg::yellow) << Term::color(Term::style::bold)
              << "Entrez un chiffre entre " << 1 << "-" << sizeof...(statements)
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
}  // namespace selection

#endif