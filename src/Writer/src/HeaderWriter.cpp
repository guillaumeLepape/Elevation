#include "HeaderWriter.h"

#include <fmt/color.h>

#include "Pause.h"
#include "UtilsWriter.h"

namespace Header {
void write(const Title& nameLevel, const Hour& hour, const Minut& minut) {
  utils::pause();

  // print level name
  fmt::print("\n ");
  fmt::print(bg(fmt::color::red) | fmt::emphasis::bold, nameLevel.get());

  utils::writeSeparators();

  // print the hour
  fmt::print(fmt::emphasis::bold, "\n {:0>2}h{:0>2}", hour.get(), minut.get());

  utils::writeSeparators();
}
}  // namespace Header