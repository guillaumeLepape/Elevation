#ifndef LEVEL_9_H
#define LEVEL_9_H

#include "combo_double_melee_weapon.h"
#include "combo_fist_melee_weapon.h"
#include "combo_quadruple_cutter.h"
#include "fight.h"
#include "header_writer.h"
#include "increase_max_life_points.h"
#include "languages.h"
#include "level_utils.h"
#include "message_writer.h"
#include "options.h"
#include "player.h"
#include "plug.h"
#include "plug_attack.h"
#include "regenerate_all_life.h"
#include "selection.h"

namespace level9 {
void start(entity::Player& player, const utils::Options& options) {
  header::write(data::level9::nameLevel, data::level9::hour,
                data::level9::minut);

  entity::Plug plug{"Psychopathe", 250, weapon::Knife()};

  action::PlugAttack plugAttack0{player, plug};
  plugAttack0.trigger();
  plugAttack0.trigger();
  plugAttack0.trigger();

  message::write(data::level9::message0, player.pseudo(), plug.name());

  action::use_weapon::trigger(player, plug, data::weapon::nameFist);

  action::RegenerateAllLife regenerateAllLife{player};
  regenerateAllLife.trigger();

  message::write(data::level9::message1, player.pseudo(), plug.name());

  regenerateAllLife.trigger();

  plug.changeWeapon(weapon::Chopper());

  action::PlugAttack plugAttack1{player, plug};
  plugAttack1.trigger();
  regenerateAllLife.trigger();

  message::write(data::level9::message2, player.pseudo(), plug.name());

  plugAttack1.trigger();
  regenerateAllLife.trigger();

  message::write(data::level9::message3, player.pseudo(), plug.name());

  plugAttack1.trigger();
  regenerateAllLife.trigger();

  message::write(data::level9::message4, player.pseudo(), plug.name());

  plug.changeWeapon(weapon::NoWeapon());

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

  fight::launch(player, std::vector{&plug}, parameters);

  regenerateAllLife.trigger();

  message::write(data::level9::message5, player.pseudo(), plug.name());

  action::IncreaseMaxLifePoints increaseMaxLifePoints{
      player, 1100, data::action::resultsIncreaseMaxLifePoints(1100)};
  increaseMaxLifePoints.trigger();

  message::write(data::level9::message6, player.pseudo(), plug.name());

  increaseMaxLifePoints.trigger();

  message::write(data::level9::message7, player.pseudo(), plug.name());

  increaseMaxLifePoints.trigger();
}
}  // namespace level9

#endif
