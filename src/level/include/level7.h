#ifndef LEVEL_7_H
#define LEVEL_7_H

#include "combo_double_melee_weapon.h"
#include "combo_fist_melee_weapon.h"
#include "combo_quadruple_cutter.h"
#include "fight.h"
#include "header_writer.h"
#include "languages.h"
#include "level_utils.h"
#include "message_writer.h"
#include "options.h"
#include "player.h"
#include "plug.h"
#include "regenerate_all_life.h"

namespace level7 {
void start(entity::Player& player, const utils::Options& options) {
  header::write(data::level7::nameLevel, data::level7::hour,
                data::level7::minut);

  entity::Plug boss{"Tueur professionnel", 200, weapon::Hammer()};

  message::write(data::level7::message0, player.pseudo(), boss.name());

  std::unique_ptr<Combo<std::string_view>> comboFistMeleeWeapon{
      new ComboFistMeleeWeapon<std::string_view>(player)};
  std::unique_ptr<Combo<std::string_view>> comboDoubleMeleeWeapon{
      new ComboDoubleMeleeWeapon<std::string_view>(player)};
  std::unique_ptr<Combo<std::string_view>> comboQuadrupleCutter{
      new ComboQuadrupleCutter<std::string_view>(player)};

  fight::parameters parameters{
      std::vector<Combo<std::string_view>*>{comboFistMeleeWeapon.get(),
                                            comboDoubleMeleeWeapon.get(),
                                            comboQuadrupleCutter.get()},
      options.noRule_};
  fight::launch(player, std::vector{&boss}, parameters);

  message::write(data::level7::message1, player.pseudo(), "");

  action::regenerate_all_life::trigger(player);
}
}  // namespace level7

#endif