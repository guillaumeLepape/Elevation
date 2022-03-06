#include "UtilsWriter.h"

#include <fmt/color.h>

namespace utils {
void writeSeparators() {
  fmt::print(fg(fmt::color::black) | fmt::emphasis::bold, "\n========");
}
}  // namespace utils
