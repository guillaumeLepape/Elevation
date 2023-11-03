#include "elevation/fight/fight_writer.h"

#include <fmt/color.h>

#include <tabulate/table.hpp>

#include "elevation/utils/pause.h"
#include "elevation/writer/utils_writer.h"

namespace elevation::fight {
namespace start {
void write() {
  utils::pause();
  fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold,
             "\n Début du combat");
}
}  // namespace start

namespace separator {
void write() {
  fmt::print(fg(fmt::color::blue) | fmt::emphasis::bold,
             "\n====================");
}
}  // namespace separator

namespace header {
void write(const int nbTurns) {
  utils::pause();
  separator::write();
  fmt::print(fg(fmt::color::black) | fmt::emphasis::bold, "\n Tour {}",
             nbTurns);
  separator::write();
}
}  // namespace header

namespace game_board {
void write(const entity::Player& player,
           const std::vector<entity::Plug*>& plugs) {
  utils::pause();

  fmt::print("\n");
  fmt::print(
      fg(fmt::color::black) | bg(fmt::color::green) | fmt::emphasis::bold,
      "Plateau de jeu");

  utils::writeSeparators();

  tabulate::Table fighters;
  tabulate::Table::Row_t nameFighters;
  tabulate::Table::Row_t lifePointsFighters;
  tabulate::Table::Row_t nameWeaponFighters;
  tabulate::Table::Row_t damageWeaponFighters;

  // build a vector of name and life points of plugs
  for (const auto& plug : plugs) {
    // display plugs only if they are not dead
    if (plug->healthBar().alive()) {
      nameFighters.push_back(plug->name());
      lifePointsFighters.push_back(
          fmt::format("{} points de vie", plug->healthBar().nbLifePoints()));
      nameWeaponFighters.push_back(plug->weapon().name);
      damageWeaponFighters.push_back(
          fmt::format("{} points d'attaque", plug->weapon().nb_damage));
    }
  }

  fighters.add_row(nameFighters);
  fighters.add_row(lifePointsFighters);
  fighters.add_row(nameWeaponFighters);
  fighters.add_row(damageWeaponFighters);

  tabulate::Table::Row_t emptyLine(std::size(nameFighters), "");
  fighters.add_row(emptyLine);

  tabulate::Table::Row_t playerLine(std::size(nameFighters), "");
  playerLine[std::size(nameFighters) / 2] = player.pseudo();
  fighters.add_row(playerLine);

  tabulate::Table::Row_t lifePlayerPoints(std::size(nameFighters), "");
  lifePlayerPoints[std::size(nameFighters) / 2] =
      fmt::format("{} points de vie", player.healthBar().nbLifePoints());
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
}  // namespace game_board

namespace remove_dead_body {
void write() {
  utils::pause();
  fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold,
             "\n Evacuation des cadavres.");
}
}  // namespace remove_dead_body

namespace end {
void write() {
  utils::pause();
  fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold,
             "\n Fin du combat\n");
}
}  // namespace end
}  // namespace elevation::fight
