#pragma once

#include "elevation/action/regenerate_all_life.h"
#include "elevation/data_files/languages.h"
#include "elevation/entity/player.h"
#include "elevation/entity/plug.h"
#include "elevation/fight/combo_double_melee_weapon.h"
#include "elevation/fight/combo_fist_melee_weapon.h"
#include "elevation/fight/combo_quadruple_cutter.h"
#include "elevation/fight/fight.h"
#include "elevation/utils/options.h"
#include "elevation/writer/header_writer.h"
#include "elevation/writer/message_writer.h"
#include "level_utils.h"

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
      options.noRule()};
  fight::launch(player, std::vector{&boss}, parameters);

  message::write(data::level7::message1, player.pseudo(), "");

  action::regenerate_all_life::trigger(player);
}
}  // namespace level7
