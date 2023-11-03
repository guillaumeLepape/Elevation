#include "elevation/writer/rules.h"

#include <fmt/color.h>

#include "elevation/utils/pause.h"
#include "elevation/writer/utils_writer.h"

namespace elevation::rules {
void write(const utils::Options& options) {
  std::ignore = std::system("clear");

  fmt::print("\n ");
  fmt::print(
      fg(fmt::color::black) | bg(fmt::color::green) | fmt::emphasis::bold,
      "Interface");
  utils::writeSeparators();

  fmt::print(
      "\n Une fois que vous avez lu un message, appuyez sur entrée "
      "pour passer au suivant.");

  if (not options.noRule()) {
    utils::pause();

    fmt::print(
        "\n Si un champ doit etre rempli pour continuer le jeu, cela "
        "sera indiqué par la couleur ");
    fmt::print(
        fg(fmt::color::black) | bg(fmt::color::yellow) | fmt::emphasis::bold,
        "noir encadré jaune");
    fmt::print(".");

    utils::pause();

    fmt::print("\n Le prénom du joueur est affiché en ");
    fmt::print(fg(fmt::color::green) | fmt::emphasis::bold, "vert");
    fmt::print(".");

    utils::pause();

    fmt::print("\n Le nom du dealer est affiché en ");
    fmt::print(fg(fmt::color::red) | fmt::emphasis::bold, "rouge");
    fmt::print(".");

    utils::pause();

    fmt::print("\n Les dialogues sont affichés en ");
    fmt::print(fg(fmt::color::blue) | fmt::emphasis::bold, "bleu");
    fmt::print(".");

    utils::pause();

    fmt::print("\n Les descriptions sont affichées en ");
    fmt::print(fg(fmt::color::magenta) | fmt::emphasis::bold, "magenta");
    fmt::print(".");

    utils::pause();

    fmt::print(
        "\n Les effets résultant des actions du joueur sont affichés en ");
    fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold, "jaune");
    fmt::print(".\n");
  }
}
}  // namespace elevation::rules
