/*!
 * \file Level9.cpp
 */

#include "Level9.h"

#include <iostream>

#include "ComboDoubleMeleeWeapon.h"
#include "ComboFistMeleeWeapon.h"
#include "ComboQuadrupleCutter.h"
#include "Fight.h"
#include "HeaderWriter.h"
#include "IncreaseMaxLifePoints.h"
#include "Languages.h"
#include "MessageWriter.h"
#include "Plug.h"
#include "PlugAttack.h"
#include "RegenerateAllLife.h"
#include "Selection.h"

void Level9::startLevel() {
  Header::write(data::Level9::nameLevel, data::Level9::hour,
                data::Level9::minut);

  Plug plug("Psychopathe", 250, weapon::Knife());

  PlugAttack plugAttack0(
      player_, plug,
      data::Action::resultPlugAttack(plug.name(), plug.weapon().nb_damage));
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

  plug.changeWeapon(weapon::Chopper());

  PlugAttack plugAttack1(player_, plug, Result(""));
  plugAttack1.triggerAction();
  regenerateAllLife.triggerAction();

  Message::write(data::Level9::message2, player_.name(), plug.name());

  plugAttack1.triggerAction();
  regenerateAllLife.triggerAction();

  Message::write(data::Level9::message3, player_.name(), plug.name());

  plugAttack1.triggerAction();
  regenerateAllLife.triggerAction();

  Message::write(data::Level9::message4, player_.name(), plug.name());

  plug.changeWeapon(weapon::NoWeapon());

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