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
      player_, &plug,
      data::Action::resultPlugAttack(plug.name(), knife->damageWeapon()));
  plugAttack0.triggerAction();
  plugAttack0.triggerAction();
  plugAttack0.triggerAction();

  MessageWriter messageWriter0(data::Level9::message0, player_->name(),
                               plug.name());
  messageWriter0.writeMessage();

  const Fist* fist = new Fist();
  UseWeapon useWeapon(player_, &plug, fist);
  useWeapon.triggerAction();

  RegenerateAllLife regenerateAllLife(player_, Result(""));
  regenerateAllLife.triggerAction();

  MessageWriter messageWriter1(data::Level9::message1, player_->name(),
                               plug.name());
  messageWriter1.writeMessage();

  regenerateAllLife.triggerAction();

  const Chopper* chopper = new Chopper();
  plug.changeWeapon(chopper);

  PlugAttack plugAttack1(
      player_, &plug,
      data::Action::resultPlugAttack(plug.name(), chopper->damageWeapon()));
  plugAttack1.triggerAction();
  regenerateAllLife.triggerAction();

  MessageWriter messageWriter2(data::Level9::message2, player_->name(),
                               plug.name());
  messageWriter2.writeMessage();

  plugAttack1.triggerAction();
  regenerateAllLife.triggerAction();

  MessageWriter messageWriter3(data::Level9::message3, player_->name(),
                               plug.name());
  messageWriter3.writeMessage();

  plugAttack1.triggerAction();
  regenerateAllLife.triggerAction();

  MessageWriter messageWriter4(data::Level9::message4, player_->name(),
                               plug.name());
  messageWriter4.writeMessage();

  const NoWeapon* noWeapon = new NoWeapon();
  plug.changeWeapon(noWeapon);

  std::unique_ptr<Combo> comboFistMeleeWeapon(
      new ComboFistMeleeWeapon(player_));
  std::unique_ptr<Combo> comboDoubleMeleeWeapon(
      new ComboDoubleMeleeWeapon(player_));
  std::unique_ptr<Combo> comboQuadrupleCutter(
      new ComboQuadrupleCutter(player_));

  Fight fight(player_, {&plug},
              {comboFistMeleeWeapon.get(), comboDoubleMeleeWeapon.get(),
               comboQuadrupleCutter.get()},
              options_.noRule_);
  fight.startFight();

  regenerateAllLife.triggerAction();

  MessageWriter messageWriter5(data::Level9::message5, player_->name(),
                               plug.name());
  messageWriter5.writeMessage();

  IncreaseMaxLifePoints increaseMaxLifePoints(
      player_, 1100, data::Action::resultsIncreaseMaxLifePoints(1100));
  increaseMaxLifePoints.triggerAction();

  MessageWriter messageWriter6(data::Level9::message6, player_->name(),
                               plug.name());
  messageWriter6.writeMessage();

  increaseMaxLifePoints.triggerAction();

  MessageWriter messageWriter7(data::Level9::message7, player_->name(),
                               plug.name());
  messageWriter7.writeMessage();

  increaseMaxLifePoints.triggerAction();

  Level9::endOfLevel();
  std::cout << "\n";
}