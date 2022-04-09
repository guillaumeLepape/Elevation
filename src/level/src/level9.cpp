#include "level9.h"

#include <iostream>

#include "combo_double_melee_weapon.h"
#include "combo_fist_melee_weapon.h"
#include "combo_quadruple_cutter.h"
#include "fight.h"
#include "header_writer.h"
#include "increase_max_life_points.h"
#include "languages.h"
#include "level_utils.h"
#include "message_writer.h"
#include "plug.h"
#include "plug_attack.h"
#include "regenerate_all_life.h"
#include "selection.h"

void Level9::start() {
  header::write(data::level9::nameLevel, data::level9::hour,
                data::level9::minut);

  entity::Plug plug{"Psychopathe", 250, weapon::Knife()};

  action::PlugAttack plugAttack0{player_, plug};
  plugAttack0.trigger();
  plugAttack0.trigger();
  plugAttack0.trigger();

  message::write(data::level9::message0, player_.pseudo(), plug.name());

  action::UseWeapon useWeapon{player_, plug, data::weapon::nameFist};
  useWeapon.trigger();

  action::RegenerateAllLife regenerateAllLife{player_};
  regenerateAllLife.trigger();

  message::write(data::level9::message1, player_.pseudo(), plug.name());

  regenerateAllLife.trigger();

  plug.changeWeapon(weapon::Chopper());

  action::PlugAttack plugAttack1{player_, plug};
  plugAttack1.trigger();
  regenerateAllLife.trigger();

  message::write(data::level9::message2, player_.pseudo(), plug.name());

  plugAttack1.trigger();
  regenerateAllLife.trigger();

  message::write(data::level9::message3, player_.pseudo(), plug.name());

  plugAttack1.trigger();
  regenerateAllLife.trigger();

  message::write(data::level9::message4, player_.pseudo(), plug.name());

  plug.changeWeapon(weapon::NoWeapon());

  std::unique_ptr<Combo<std::string_view>> comboFistMeleeWeapon{
      new ComboFistMeleeWeapon<std::string_view>(player_)};
  std::unique_ptr<Combo<std::string_view>> comboDoubleMeleeWeapon{
      new ComboDoubleMeleeWeapon<std::string_view>(player_)};
  std::unique_ptr<Combo<std::string_view>> comboQuadrupleCutter{
      new ComboQuadrupleCutter<std::string_view>(player_)};

  fight::parameters parameters{
      std::vector<Combo<std::string_view>*>{comboFistMeleeWeapon.get(),
                                            comboDoubleMeleeWeapon.get(),
                                            comboQuadrupleCutter.get()},
      options_.noRule_};

  fight::launch(player_, std::vector{&plug}, parameters);

  regenerateAllLife.trigger();

  message::write(data::level9::message5, player_.pseudo(), plug.name());

  action::IncreaseMaxLifePoints increaseMaxLifePoints{
      player_, 1100, data::action::resultsIncreaseMaxLifePoints(1100)};
  increaseMaxLifePoints.trigger();

  message::write(data::level9::message6, player_.pseudo(), plug.name());

  increaseMaxLifePoints.trigger();

  message::write(data::level9::message7, player_.pseudo(), plug.name());

  increaseMaxLifePoints.trigger();
}