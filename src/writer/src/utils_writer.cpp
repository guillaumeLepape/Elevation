#include "elevation/writer/utils_writer.h"

#include <fmt/color.h>

namespace elevation::utils {
void writeSeparators() {
  fmt::print(fg(fmt::color::black) | fmt::emphasis::bold, "\n========");
}
}  // namespace elevation::utils
