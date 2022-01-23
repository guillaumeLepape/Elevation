#include "ComboWriter.h"

#include <cpp-terminal/terminal.h>

#include "Pause.h"
#include "UtilsWriter.h"

ComboWriter::ComboWriter(const Combo* const combo) : combo_{combo} {}

void ComboWriter::informationCombo() const {
  utils::pause();

  std::cout << "\n " << Term::color(Term::bg::magenta)
            << Term::color(Term::style::bold) << combo_->title()
            << Term::color(Term::bg::reset) << Term::color(Term::style::reset);

  utils::writeSeparators();

  std::cout << "\n " << Term::color(Term::fg::magenta)
            << Term::color(Term::style::bold)
            << "Action à réaliser pour déclencher le combo : "
            << Term::color(Term::fg::reset) << Term::color(Term::style::reset);

  std::cout << Term::color(Term::fg::yellow) << Term::color(Term::style::bold)
            << combo_->triggerStatement() << Term::color(Term::fg::reset)
            << Term::color(Term::style::reset);

  std::cout << "\n " << Term::color(Term::fg::magenta)
            << Term::color(Term::style::bold)
            << "Action débloqué : " << Term::color(Term::fg::reset)
            << Term::color(Term::style::reset);

  std::cout << Term::color(Term::fg::yellow) << Term::color(Term::style::bold)
            << combo_->triggeredStatement() << Term::color(Term::fg::reset)
            << Term::color(Term::style::reset);

  std::cout << "\n " << Term::color(Term::fg::magenta)
            << Term::color(Term::style::bold)
            << "Malus associé : " << Term::color(Term::fg::reset)
            << Term::color(Term::style::reset);

  std::cout << Term::color(Term::fg::yellow) << Term::color(Term::style::bold)
            << combo_->malusStatement() << Term::color(Term::fg::reset)
            << Term::color(Term::style::reset);
}