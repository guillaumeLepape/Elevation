#ifndef SELECTION_WRITER_H
#define SELECTION_WRITER_H

/*!
 * \file SelectionWriter.h
 */

#include <string_view>
#include <vector>

#include "Pause.h"

class SelectionWriter {
 private:
  std::string title_;
  std::vector<std::string> statements_;

 public:
  SelectionWriter(const std::string& title,
                  const std::vector<std::string>& statements)
      : title_(title), statements_(statements) {}

  void writeSelection() const {
    Pause::pause();

    std::cout << "\n " << Term::color(Term::fg::black)
              << Term::color(Term::bg::green) << Term::color(Term::style::bold)
              << title_ << Term::color(Term::fg::reset)
              << Term::color(Term::bg::reset)
              << Term::color(Term::style::reset);

    std::cout << "\n"
              << Term::color(Term::fg::black) << Term::color(Term::style::bold)
              << "========" << Term::color(Term::fg::reset)
              << Term::color(Term::style::reset);

    for (long unsigned int i = 0; i < statements_.size(); i++) {
      std::cout << "\n " << std::to_string(i + 1) << "- "
                << Term::color(Term::fg::yellow)
                << Term::color(Term::style::bold) << statements_[i]
                << Term::color(Term::fg::reset)
                << Term::color(Term::style::reset);
    }

    if (statements_.size() != 1) {
      std::cout << "\n " << Term::color(Term::fg::black)
                << Term::color(Term::bg::yellow)
                << Term::color(Term::style::bold) << "Entrez un chiffre entre "
                << 1 << "-" << statements_.size()
                << Term::color(Term::fg::reset) << Term::color(Term::bg::reset)
                << Term::color(Term::style::reset) << " : ";
    } else {
      std::cout << "\n " << Term::color(Term::fg::black)
                << Term::color(Term::bg::yellow)
                << Term::color(Term::style::bold)
                << "Entrez un chiffre égale à 1" << Term::color(Term::fg::reset)
                << Term::color(Term::bg::reset)
                << Term::color(Term::style::reset) << " : ";
    }
  }
};

#endif