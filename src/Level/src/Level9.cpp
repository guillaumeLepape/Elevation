/*!
 * \file Level9.cpp
 */

#include "Level9.h"

#include <iostream>

#include "AK47.h"
#include "Chopper.h"
#include "ComboDoubleMeleeWeapon.h"
#include "ComboFistMeleeWeapon.h"
#include "ComboQuadrupleCutter.h"
#include "Fight.h"
#include "Fist.h"
#include "HeaderWriter.h"
#include "IncreaseMaxLifePoints.h"
#include "Knife.h"
#include "Languages.h"
#include "MessageWriter.h"
#include "NoWeapon.h"
#include "Plug.h"
#include "PlugAttack.h"
#include "RegenerateAllLife.h"
#include "Selection.h"

void Level9::startLevel() {
  Header::write(data::Level9::nameLevel, data::Level9::hour,
                data::Level9::minut);

  const Knife* knife = new Knife();
  Plug plug("Psychopathe", 250, knife);

  PlugAttack plugAttack0(
      player_, plug,
      data::Action::resultPlugAttack(plug.name(), knife->damageWeapon()));
  plugAttack0.triggerAction();
  plugAttack0.triggerAction();
  plugAttack0.triggerAction();

  Message::write(data::Level9::message0, player_.name(), plug.name());

  UseWeapon useWeapon(player_, plug, data::Weapon::nameFist);
  useWeapon.triggerAction();

  RegenerateAllLife regenerateAllLife(player_, Result(""));
  regenerateAllLife.triggerAction();

  Message::write(data::Level9::message1, player_.name(), plug.name());

  regenerateAllLife.triggerAction();

  const Chopper* chopper = new Chopper();
  plug.changeWeapon(chopper);

  PlugAttack plugAttack1(
      player_, plug,
      data::Action::resultPlugAttack(plug.name(), chopper->damageWeapon()));
  plugAttack1.triggerAction();
  regenerateAllLife.triggerAction();

  Message::write(data::Level9::message2, player_.name(), plug.name());

  plugAttack1.triggerAction();
  regenerateAllLife.triggerAction();

  Message::write(data::Level9::message3, player_.name(), plug.name());

  plugAttack1.triggerAction();
  regenerateAllLife.triggerAction();

  Message::write(data::Level9::message4, player_.name(), plug.name());

  const NoWeapon* noWeapon = new NoWeapon();
  plug.changeWeapon(noWeapon);

  std::unique_ptr<Combo> comboFistMeleeWeapon(
      new ComboFistMeleeWeapon(player_));
  std::unique_ptr<Combo> comboDoubleMeleeWeapon(
      new ComboDoubleMeleeWeapon(player_));
  std::unique_ptr<Combo> comboQuadrupleCutter(
      new ComboQuadrupleCutter(player_));

  Fight fight(&player_, {&plug},
              {comboFistMeleeWeapon.get(), comboDoubleMeleeWeapon.get(),
               comboQuadrupleCutter.get()},
              options_.noRule_);
  fight.startFight();

  regenerateAllLife.triggerAction();

  Message::write(data::Level9::message5, player_.name(), plug.name());

  IncreaseMaxLifePoints increaseMaxLifePoints(
      player_, 1100, data::Action::resultsIncreaseMaxLifePoints(1100));
  increaseMaxLifePoints.triggerAction();

  Message::write(data::Level9::message6, player_.name(), plug.name());

  increaseMaxLifePoints.triggerAction();

  Message::write(data::Level9::message7, player_.name(), plug.name());

  increaseMaxLifePoints.triggerAction();

  Level9::endOfLevel();
  std::cout << "\n";
}