#include "UtilsWriter.h"

namespace utils {
void writeSeparators() {
  std::cout << "\n"
            << Term::color(Term::fg::black) << Term::color(Term::style::bold)
            << "========" << Term::color(Term::fg::reset)
            << Term::color(Term::style::reset);
}
}  // namespace utils
