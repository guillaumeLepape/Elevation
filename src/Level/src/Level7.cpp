#include "Level7.h"

#include <iostream>

#include "ComboDoubleMeleeWeapon.h"
#include "ComboFistMeleeWeapon.h"
#include "ComboQuadrupleCutter.h"
#include "Fight.h"
#include "HeaderWriter.h"
#include "Languages.h"
#include "LevelUtils.h"
#include "MessageWriter.h"
#include "Player.h"
#include "Plug.h"
#include "RegenerateAllLife.h"

void Level7::start() {
  header::write(data::level7::nameLevel, data::level7::hour,
                data::level7::minut);

  entity::Plug boss{"Tueur professionnel", 200, weapon::Hammer()};

  message::write(data::level7::message0, player_.pseudo(), boss.name());

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
  fight::launch(player_, std::vector{&boss}, parameters);
  //   Fight fight{
  //       player_,
  //       {&boss},
  //       {comboFistMeleeWeapon, comboDoubleMeleeWeapon, comboQuadrupleCutter},
  //       options_.noRule_};
  //   fight.startFight();

  message::write(data::level7::message1, player_.pseudo(), "");

  action::RegenerateAllLife regenerateAllLife{player_};
  regenerateAllLife.trigger();
}