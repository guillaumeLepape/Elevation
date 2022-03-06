#include "ComboWriter.h"

#include <fmt/color.h>

#include "Pause.h"
#include "UtilsWriter.h"

ComboWriter::ComboWriter(const Combo* const combo) : combo_{combo} {}

void ComboWriter::informationCombo() const {
  utils::pause();

  fmt::print("\n ");
  fmt::print(bg(fmt::color::magenta) | fmt::emphasis::bold, combo_->title());

  utils::writeSeparators();

  fmt::print(fg(fmt::color::magenta) | fmt::emphasis::bold,
             "\n Action à réaliser pour déclencher le combo : ");
  fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold,
             combo_->triggerStatement());

  fmt::print(fg(fmt::color::magenta) | fmt::emphasis::bold,
             "\n Action débloqué : ");
  fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold,
             combo_->triggeredStatement());

  fmt::print(fg(fmt::color::magenta) | fmt::emphasis::bold,
             "\n Malus associé : ");
  fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold,
             combo_->malusStatement());
}