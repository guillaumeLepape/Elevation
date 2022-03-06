#include "FightWriter.h"

#include <fmt/color.h>

#include <tabulate/table.hpp>

#include "Pause.h"
#include "UtilsWriter.h"

FightWriter::FightWriter(const entity::Player* const player,
                         const std::vector<entity::Plug*>& plugs)
    : player_{player}, plugs_{plugs} {
  utils::pause();
  fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold,
             "\n Début du combat");
}

void FightWriter::writeSeparator() const {
  fmt::print(fg(fmt::color::blue) | fmt::emphasis::bold,
             "\n====================");
}

void FightWriter::writeHeader(const int nbTurns) const {
  utils::pause();

  writeSeparator();

  fmt::print(fg(fmt::color::black) | fmt::emphasis::bold, "\n Tour {}",
             nbTurns);

  writeSeparator();
}

void FightWriter::writeGameBoard() const {
  utils::pause();

  fmt::print("\n");
  fmt::print(
      fg(fmt::color::black) | bg(fmt::color::green) | fmt::emphasis::bold,
      "Plateau de jeu");

  utils::writeSeparators();

  tabulate::Table fighters;
  std::vector<variant<std::string, const char*, tabulate::Table>> nameFighters;
  std::vector<variant<std::string, const char*, tabulate::Table>>
      lifePointsFighters;
  std::vector<variant<std::string, const char*, tabulate::Table>>
      nameWeaponFighters;
  std::vector<variant<std::string, const char*, tabulate::Table>>
      damageWeaponFighters;

  // build a vector of name and life points of plugs
  for (std::size_t i = 0; i < std::size(plugs_); i++) {
    // display plugs only if they are not dead
    if (plugs_[i]->healthBar().alive()) {
      nameFighters.push_back(plugs_[i]->name());
      lifePointsFighters.push_back(fmt::format(
          "{} points de vie", plugs_[i]->healthBar().nbLifePoints()));
      nameWeaponFighters.push_back(plugs_[i]->weapon().name);
      damageWeaponFighters.push_back(
          fmt::format("{} points d'attaque", plugs_[i]->weapon().nb_damage));
    }
  }

  fighters.add_row(nameFighters);
  fighters.add_row(lifePointsFighters);
  fighters.add_row(nameWeaponFighters);
  fighters.add_row(damageWeaponFighters);

  std::vector<variant<std::string, const char*, tabulate::Table>> emptyLine(
      std::size(nameFighters), "");
  fighters.add_row(emptyLine);

  std::vector<variant<std::string, const char*, tabulate::Table>> playerLine(
      std::size(nameFighters), "");
  playerLine[std::size(nameFighters) / 2] = player_->pseudo();
  fighters.add_row(playerLine);

  std::vector<variant<std::string, const char*, tabulate::Table>>
      lifePlayerPoints(std::size(nameFighters), "");
  lifePlayerPoints[std::size(nameFighters) / 2] =
      fmt::format("{} points de vie", player_->healthBar().nbLifePoints());
  fighters.add_row(lifePlayerPoints);

  fighters.format()
      .font_style({tabulate::FontStyle::bold})
      .border_top("")
      .border_bottom(" ")
      .border_left(" ")
      .border_right(" ")
      .corner(" ");

  fighters[0]
      .format()
      .padding_top(0)
      .padding_bottom(1)
      .font_align(tabulate::FontAlign::center)
      .font_color(tabulate::Color::red);

  fighters[1]
      .format()
      .font_align(tabulate::FontAlign::center)
      .font_color(tabulate::Color::yellow);

  fighters[2]
      .format()
      .font_align(tabulate::FontAlign::center)
      .font_color(tabulate::Color::magenta);

  fighters[3]
      .format()
      .font_align(tabulate::FontAlign::center)
      .font_color(tabulate::Color::magenta);

  fighters[4].format().padding_top(1).padding_bottom(1);

  fighters[5]
      .format()
      .padding_top(1)
      .padding_bottom(1)
      .font_align(tabulate::FontAlign::center)
      .font_color(tabulate::Color::green);

  fighters[6]
      .format()
      .font_align(tabulate::FontAlign::center)
      .font_color(tabulate::Color::yellow);

  std::cout << "\n" << fighters;
}

void FightWriter::writeRemoveDeadBody() {
  utils::pause();
  fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold,
             "\n Evacuation des cadavres.");
}

void FightWriter::writeEndOfFight() const {
  utils::pause();
  fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold, "\n Fin du combat");
}
