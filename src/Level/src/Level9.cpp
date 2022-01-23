#include "Level9.h"

#include <iostream>

#include "ComboDoubleMeleeWeapon.h"
#include "ComboFistMeleeWeapon.h"
#include "ComboQuadrupleCutter.h"
#include "Fight.h"
#include "HeaderWriter.h"
#include "IncreaseMaxLifePoints.h"
#include "Languages.h"
#include "LevelUtils.h"
#include "MessageWriter.h"
#include "Plug.h"
#include "PlugAttack.h"
#include "RegenerateAllLife.h"
#include "Selection.h"

void Level9::start() {
  Header::write(data::Level9::nameLevel, data::Level9::hour,
                data::Level9::minut);

  entity::Plug plug{"Psychopathe", 250, weapon::Knife()};

  action::PlugAttack plugAttack0{
      player_, plug,
      data::Action::resultPlugAttack(plug.name(), plug.weapon().nb_damage)};
  plugAttack0.trigger();
  plugAttack0.trigger();
  plugAttack0.trigger();

  Message::write(data::Level9::message0, player_.pseudo(), plug.name());

  action::UseWeapon useWeapon{player_, plug, data::Weapon::nameFist};
  useWeapon.trigger();

  action::RegenerateAllLife regenerateAllLife{player_, Result("")};
  regenerateAllLife.trigger();

  Message::write(data::Level9::message1, player_.pseudo(), plug.name());

  regenerateAllLife.trigger();

  plug.changeWeapon(weapon::Chopper());

  action::PlugAttack plugAttack1{player_, plug, Result("")};
  plugAttack1.trigger();
  regenerateAllLife.trigger();

  Message::write(data::Level9::message2, player_.pseudo(), plug.name());

  plugAttack1.trigger();
  regenerateAllLife.trigger();

  Message::write(data::Level9::message3, player_.pseudo(), plug.name());

  plugAttack1.trigger();
  regenerateAllLife.trigger();

  Message::write(data::Level9::message4, player_.pseudo(), plug.name());

  plug.changeWeapon(weapon::NoWeapon());

  std::unique_ptr<Combo> comboFistMeleeWeapon{
      new ComboFistMeleeWeapon(player_)};
  std::unique_ptr<Combo> comboDoubleMeleeWeapon{
      new ComboDoubleMeleeWeapon(player_)};
  std::unique_ptr<Combo> comboQuadrupleCutter{
      new ComboQuadrupleCutter(player_)};

  Fight fight{&player_,
              {&plug},
              {comboFistMeleeWeapon.get(), comboDoubleMeleeWeapon.get(),
               comboQuadrupleCutter.get()},
              options_.noRule_};
  fight.startFight();

  regenerateAllLife.trigger();

  Message::write(data::Level9::message5, player_.pseudo(), plug.name());

  action::IncreaseMaxLifePoints increaseMaxLifePoints{
      player_, 1100, data::Action::resultsIncreaseMaxLifePoints(1100)};
  increaseMaxLifePoints.trigger();

  Message::write(data::Level9::message6, player_.pseudo(), plug.name());

  increaseMaxLifePoints.trigger();

  Message::write(data::Level9::message7, player_.pseudo(), plug.name());

  increaseMaxLifePoints.trigger();

  endoflevel(player_);
  std::cout << "\n";
}