#include "ActionWriter.h"

#include <cpp-terminal/terminal.h>

#include "Pause.h"

namespace action {
void writeStatement(const Statement& statement) {
  std::cout << "\n " << Term::color(Term::fg::black)
            << Term::color(Term::bg::yellow) << Term::color(Term::style::bold)
            << statement.get() << Term::color(Term::fg::reset)
            << Term::color(Term::bg::reset) << Term::color(Term::style::reset)
            << " : ";
}
void writeResult(const Result& result) {
  utils::pause();
  std::cout << "\n " << Term::color(Term::fg::yellow)
            << Term::color(Term::style::bold) << result.get()
            << Term::color(Term::fg::reset) << Term::color(Term::style::reset);
}
}  // namespace action