/*!
 * \file HeaderWriter.cpp
 */

#include "HeaderWriter.h"

#include <cpp-terminal/terminal.h>

#include <iomanip>

#include "Pause.h"

namespace Header {
void write(const Title& nameLevel, const Hour& hour, const Minut& minut) {
  Pause::pause();

  // print level name
  std::cout << "\n " << Term::color(Term::bg::red)
            << Term::color(Term::style::bold) << nameLevel.get()
            << Term::color(Term::bg::reset) << Term::color(Term::style::reset);

  std::cout << "\n"
            << Term::color(Term::fg::black) << Term::color(Term::style::bold)
            << "========" << Term::color(Term::fg::reset)
            << Term::color(Term::style::reset);

  // print the hour
  std::cout << "\n " << Term::color(Term::style::bold);
  std::cout << std::setfill('0') << std::setw(2) << hour.get();
  std::cout << "h";
  std::cout << std::setfill('0') << std::setw(2) << minut.get();
  std::cout << Term::color(Term::style::reset);

  std::cout << "\n"
            << Term::color(Term::fg::black) << Term::color(Term::style::bold)
            << "========" << Term::color(Term::fg::reset)
            << Term::color(Term::style::reset);
}
}  // namespace Header