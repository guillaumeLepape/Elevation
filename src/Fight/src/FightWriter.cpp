/*!
 * \file FightWriter.cpp
 */

#include "FightWriter.h"

#include <cpp-terminal/terminal.h>

#include <tabulate/table.hpp>

#include "Pause.h"
#include "UtilsWriter.h"

FightWriter::FightWriter(const Player* const player,
                         const std::vector<Plug*>& plugs)
    : player_(player), plugs_(plugs) {
  Pause::pause();
  std::cout << "\n " << Term::color(Term::fg::yellow)
            << Term::color(Term::style::bold) << "Début du combat"
            << Term::color(Term::fg::reset) << Term::color(Term::style::reset);
}

void FightWriter::writeSeparator() const {
    std::cout << "\n"
            << Term::color(Term::fg::blue) << Term::color(Term::style::bold)
            << "====================" << Term::color(Term::fg::reset)
            << Term::color(Term::style::reset);
}


void FightWriter::writeHeader(const int nbTurns) const {
  Pause::pause();

  writeSeparator();

  std::cout << "\n " << Term::color(Term::fg::black)
            << Term::color(Term::bg::green) << Term::color(Term::style::bold)
            << "Tour " << nbTurns << Term::color(Term::fg::reset)
            << Term::color(Term::bg::reset) << Term::color(Term::style::reset);

  writeSeparator();
}

void FightWriter::writeGameBoard() const {
  Pause::pause();

  std::cout << "\n"
            << Term::color(Term::fg::black) << Term::color(Term::bg::green)
            << Term::color(Term::style::bold) << "Plateau de jeu"
            << Term::color(Term::fg::reset) << Term::color(Term::bg::reset)
            << Term::color(Term::style::reset);

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
  for (long unsigned int i = 0; i < plugs_.size(); i++) {
    // display plugs only if they are not dead
    if (!(plugs_[i]->dead())) {
      nameFighters.push_back(plugs_[i]->name());
      lifePointsFighters.push_back(std::to_string(plugs_[i]->nbLifePoints()) +
                                   " points de vie");
      nameWeaponFighters.push_back(plugs_[i]->weapon()->name());
      damageWeaponFighters.push_back(
          std::to_string(plugs_[i]->weapon()->damageWeapon()) +
          " points d'attaque");
    }
  }

  fighters.add_row(nameFighters);
  fighters.add_row(lifePointsFighters);
  fighters.add_row(nameWeaponFighters);
  fighters.add_row(damageWeaponFighters);

  std::vector<variant<std::string, const char*, tabulate::Table>> emptyLine(
      nameFighters.size(), "");
  fighters.add_row(emptyLine);

  std::vector<variant<std::string, const char*, tabulate::Table>> playerLine(
      nameFighters.size(), "");
  playerLine[nameFighters.size() / 2] = player_->name();
  fighters.add_row(playerLine);

  std::vector<variant<std::string, const char*, tabulate::Table>>
      lifePlayerPoints(nameFighters.size(), "");
  lifePlayerPoints[nameFighters.size() / 2] =
      std::to_string(player_->nbLifePoints()) + " points de vie";
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
  Pause::pause();
  std::cout << "\n " << Term::color(Term::fg::yellow)
            << Term::color(Term::style::bold) << "Evacuation des cadavres."
            << Term::color(Term::fg::reset) << Term::color(Term::style::reset);
}

void FightWriter::writeEndOfFight() const {
  Pause::pause();
  std::cout << "\n " << Term::color(Term::fg::yellow)
            << Term::color(Term::style::bold) << "Fin du combat"
            << Term::color(Term::fg::reset) << Term::color(Term::style::reset);
}
