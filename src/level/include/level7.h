#ifndef LEVEL_7_H
#define LEVEL_7_H

#include "combo.h"
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

  auto comboFistMeleeWeapon = combo_v2::ComboFistMeleeWeapon{};
  auto comboDoubleMeleeWeapon = combo_v2::ComboDoubleMeleeWeapon{};
  auto comboQuadrupleCutter = combo_v2::ComboQuadrupleCutter{};

  fight::parameters parameters{
      std::vector<combo_v2::Combo<std::string_view>*>{
          comboFistMeleeWeapon, comboDoubleMeleeWeapon, comboQuadrupleCutter},
      options.noRule};
  fight::launch(player, std::vector{&boss}, parameters);

  message::write(data::level7::message1, player.pseudo(), "");

  action::regenerate_all_life::trigger(player);
}
}  // namespace level7

#endif
