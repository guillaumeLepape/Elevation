/*!
 * \file HeaderWriter.cpp
 */

#include "HeaderWriter.h"

#include <cpp-terminal/terminal.h>

#include <iomanip>

#include "Pause.h"
#include "UtilsWriter.h"

namespace Header {
void write(const Title& nameLevel, const Hour& hour, const Minut& minut) {
  utils::pause();

  // print level name
  std::cout << "\n " << Term::color(Term::bg::red)
            << Term::color(Term::style::bold) << nameLevel.get()
            << Term::color(Term::bg::reset) << Term::color(Term::style::reset);

  utils::writeSeparators();

  // print the hour
  std::cout << "\n " << Term::color(Term::style::bold);
  std::cout << std::setfill('0') << std::setw(2) << hour.get();
  std::cout << "h";
  std::cout << std::setfill('0') << std::setw(2) << minut.get();
  std::cout << Term::color(Term::style::reset);

  utils::writeSeparators();
}
}  // namespace Header