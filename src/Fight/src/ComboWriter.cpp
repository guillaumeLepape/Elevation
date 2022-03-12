#include "ComboWriter.h"

#include <fmt/color.h>

#include "Pause.h"
#include "UtilsWriter.h"

namespace combo {
void write(const Combo* const combo) {
  utils::pause();

  fmt::print("\n ");
  fmt::print(bg(fmt::color::magenta) | fmt::emphasis::bold, combo->title());

  utils::writeSeparators();

  fmt::print(fg(fmt::color::magenta) | fmt::emphasis::bold,
             "\n Action à réaliser pour déclencher le combo : ");
  fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold,
             combo->triggerStatement());

  fmt::print(fg(fmt::color::magenta) | fmt::emphasis::bold,
             "\n Action débloqué : ");
  fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold,
             combo->triggeredStatement());

  fmt::print(fg(fmt::color::magenta) | fmt::emphasis::bold,
             "\n Malus associé : ");
  fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold,
             combo->malusStatement());
}
}  // namespace combo