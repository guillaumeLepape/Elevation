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
  Header::write(data::Level7::nameLevel, data::Level7::hour,
                data::Level7::minut);

  entity::Plug boss{"Tueur professionnel", 200, weapon::Hammer()};

  Message::write(data::Level7::message0, player_.pseudo(), boss.name());

  std::unique_ptr<Combo> comboFistMeleeWeapon{
      new ComboFistMeleeWeapon(player_)};
  std::unique_ptr<Combo> comboDoubleMeleeWeapon{
      new ComboDoubleMeleeWeapon(player_)};
  std::unique_ptr<Combo> comboQuadrupleCutter{
      new ComboQuadrupleCutter(player_)};

  Fight fight{&player_,
              {&boss},
              {comboFistMeleeWeapon.get(), comboDoubleMeleeWeapon.get(),
               comboQuadrupleCutter.get()},
              options_.noRule_};
  fight.startFight();

  Message::write(data::Level7::message1, player_.pseudo(), "");

  action::RegenerateAllLife regenerateAllLife{player_, Result("")};
  regenerateAllLife.trigger();
}