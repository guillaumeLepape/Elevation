/*!
 * \file Level7.cpp
 */

#include "Level7.h"

#include <iostream>

#include "ComboDoubleMeleeWeapon.h"
#include "ComboFistMeleeWeapon.h"
#include "ComboQuadrupleCutter.h"
#include "Fight.h"
#include "Hammer.h"
#include "HeaderWriter.h"
#include "Knife.h"
#include "Languages.h"
#include "MessageWriter.h"
#include "Ninemm.h"
#include "Player.h"
#include "Plug.h"
#include "RegenerateAllLife.h"

void Level7::startLevel() {
  Header::write(data::Level7::nameLevel, data::Level7::hour,
                data::Level7::minut);

  Plug boss("Tueur professionnel", 200, new Hammer());

  MessageWriter messageWriter0(data::Level7::message0, player_->name(),
                               boss.name());
  messageWriter0.writeMessage();

  std::unique_ptr<Combo> comboFistMeleeWeapon(
      new ComboFistMeleeWeapon(player_));
  std::unique_ptr<Combo> comboDoubleMeleeWeapon(
      new ComboDoubleMeleeWeapon(player_));
  std::unique_ptr<Combo> comboQuadrupleCutter(
      new ComboQuadrupleCutter(player_));

  Fight fight(player_, {&boss},
              {comboFistMeleeWeapon.get(), comboDoubleMeleeWeapon.get(),
               comboQuadrupleCutter.get()},
              options_.noRule_);
  fight.startFight();

  MessageWriter messageWriter1(data::Level7::message1, player_->name(), "");
  messageWriter1.writeMessage();

  RegenerateAllLife regenerateAllLife(player_, "", "");
  regenerateAllLife.triggerAction();

  Level::endOfLevel();
  std::cout << "\n";
}