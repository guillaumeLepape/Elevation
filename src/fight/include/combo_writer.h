#pragma once

#include <fmt/color.h>

#include "combo.h"
#include "pause.h"
#include "utils_writer.h"

namespace combo {
template <utils::Printable T>
void write(const Combo<T>& combo) {
  utils::pause();

  fmt::print("\n ");
  fmt::print(bg(fmt::color::magenta) | fmt::emphasis::bold, combo.title());

  utils::writeSeparators();

  fmt::print(fg(fmt::color::magenta) | fmt::emphasis::bold,
             "\n Action à réaliser pour déclencher le combo : ");
  fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold,
             combo.triggerStatement());

  fmt::print(fg(fmt::color::magenta) | fmt::emphasis::bold,
             "\n Action débloqué : ");
  fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold,
             combo.triggeredStatement());

  fmt::print(fg(fmt::color::magenta) | fmt::emphasis::bold,
             "\n Malus associé : ");
  fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold,
             combo.malusStatement());
}
}  // namespace combo
