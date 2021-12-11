/*!
 * \file Rules.cpp
 */

#include "Rules.h"

#include <cpp-terminal/terminal.h>

#include "Pause.h"
#include "UtilsWriter.h"

namespace Rules {
void write(const utils::Options& options) {
  std::ignore = std::system("clear");

  std::cout << "\n " << Term::color(Term::fg::black)
            << Term::color(Term::bg::green) << Term::color(Term::style::bold)
            << "Interface" << Term::color(Term::fg::reset)
            << Term::color(Term::bg::reset) << Term::color(Term::style::reset);

  utils::writeSeparators();

  std::cout << "\n Une fois que vous avez lu un message, appuyez sur entrée "
               "pour passer au suivant.";

  if (!options.noRule_) {
    utils::pause();

    std::cout << "\n Si un champ doit etre rempli pour continuer le jeu, cela "
                 "sera indiqué par la couleur "
              << Term::color(Term::fg::black) << Term::color(Term::bg::yellow)
              << Term::color(Term::style::bold) << "noir encadré jaune"
              << Term::color(Term::fg::reset) << Term::color(Term::bg::reset)
              << Term::color(Term::style::reset) << ".";

    utils::pause();

    std::cout << "\n Le prénom du joueur est affiché en "
              << Term::color(Term::fg::green) << Term::color(Term::style::bold)
              << "vert" << Term::color(Term::fg::reset)
              << Term::color(Term::style::reset) << ".";

    utils::pause();

    std::cout << "\n Le nom du dealer est affiché en "
              << Term::color(Term::fg::red) << Term::color(Term::style::bold)
              << "rouge" << Term::color(Term::fg::reset)
              << Term::color(Term::style::reset) << ".";

    utils::pause();

    std::cout << "\n Les dialogues sont affichés en "
              << Term::color(Term::fg::blue) << Term::color(Term::style::bold)
              << "bleu" << Term::color(Term::fg::reset)
              << Term::color(Term::style::reset) << ".";

    utils::pause();

    std::cout << "\n Les descriptions sont affichées en "
              << Term::color(Term::fg::magenta)
              << Term::color(Term::style::bold) << "magenta"
              << Term::color(Term::fg::reset) << Term::color(Term::style::reset)
              << ".";

    utils::pause();

    std::cout
        << "\n Les effets résultant des actions du joueur sont affichés en "
        << Term::color(Term::fg::yellow) << Term::color(Term::style::bold)
        << "jaune" << Term::color(Term::fg::reset)
        << Term::color(Term::style::reset) << ".";

    std::cout << "\n";
  }
}
}  // namespace Rules