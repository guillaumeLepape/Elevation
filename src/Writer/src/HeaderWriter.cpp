/*!
 * \file HeaderWriter.cpp
 */

#include "HeaderWriter.h"

#include <cpp-terminal/terminal.h>

#include <iomanip>

#include "Pause.h"

HeaderWriter::HeaderWriter(const std::string_view& nameLevel, const Hour& hour,
                           const Minut& minut)
    : nameLevel_(nameLevel), hour_(hour), minut_(minut) {}

void HeaderWriter::writeHeader() const {
  Pause::pause();

  // print level name
  std::cout << "\n " << Term::color(Term::bg::red)
            << Term::color(Term::style::bold) << nameLevel_
            << Term::color(Term::bg::reset) << Term::color(Term::style::reset);

  std::cout << "\n"
            << Term::color(Term::fg::black) << Term::color(Term::style::bold)
            << "========" << Term::color(Term::fg::reset)
            << Term::color(Term::style::reset);

  // print the hour
  std::cout << "\n " << Term::color(Term::style::bold);
  std::cout << std::setfill('0') << std::setw(2) << hour_.get();
  std::cout << "h";
  std::cout << std::setfill('0') << std::setw(2) << minut_.get();
  std::cout << Term::color(Term::style::reset);

  std::cout << "\n"
            << Term::color(Term::fg::black) << Term::color(Term::style::bold)
            << "========" << Term::color(Term::fg::reset)
            << Term::color(Term::style::reset);
}