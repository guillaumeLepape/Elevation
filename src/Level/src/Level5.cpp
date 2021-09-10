/*!
 * \file Level5.cpp
 */

#include "Level5.h"

#include <iostream>

#include "ComboDoubleMeleeWeapon.h"
#include "ComboFistMeleeWeapon.h"
#include "ComboQuadrupleCutter.h"
#include "Cutter.h"
#include "Fight.h"
#include "Fist.h"
#include "HeaderWriter.h"
#include "Katana.h"
#include "Knife.h"
#include "Languages.h"
#include "MessageWriter.h"
#include "RegenerateAllLife.h"
#include "TutorialWriter.h"

void Level5::startLevel() {
  Header::write(data::Level5::nameLevel, data::Level5::hour,
                data::Level5::minut);

  Plug guetteur("Guetteur", 35, new Fist());

  MessageWriter messageWriter0(data::Level5::message0, player_->name(),
                               guetteur.name());
  messageWriter0.writeMessage();

  MessageWriter messageWriter1(data::Level5::message1, player_->name(),
                               guetteur.name());
  messageWriter1.writeMessage();

  if (!options_.noRule_) {
    Tutorial::write(
        data::Tutorial::titleCombatSystem,
        data::Tutorial::statementCombatSystem(player_->maxLifePoints()));
  }

  if (!options_.noRule_) {
    Tutorial::write(data::Tutorial::titleCombo, data::Tutorial::statementCombo);
  }

  // Declare combos
  std::unique_ptr<Combo> comboFistMeleeWeapon(
      new ComboFistMeleeWeapon(player_));
  std::unique_ptr<Combo> comboDoubleMeleeWeapon(
      new ComboDoubleMeleeWeapon(player_));
  std::unique_ptr<Combo> comboQuadrupleCutter(
      new ComboQuadrupleCutter(player_));

  // First fight (introduction to Fist - Melee Weapon combo)
  if (!options_.noRule_) {
    Tutorial::write(data::Tutorial::titleComboFistMeleeWeapon,
                    data::Tutorial::statementComboFistMeleeWeapon);
  }

  Fight firstFight(player_, {&guetteur}, {comboFistMeleeWeapon.get()},
                   options_.noRule_, false);
  firstFight.startFight();

  // Second fight (introduction to Double melee Weapon combo )
  Plug garde("Garde", 50, new Fist());

  MessageWriter messageWriter2(data::Level5::message2, player_->name(),
                               garde.name());
  messageWriter2.writeMessage();

  if (!options_.noRule_) {
    Tutorial::write(data::Tutorial::titleComboDoubleMeleeWeapon,
                    data::Tutorial::statementComboDoubleMeleeWeapon);
  }

  Fight secondFight(player_, {&garde}, {comboDoubleMeleeWeapon.get()},
                    options_.noRule_, false);
  secondFight.startFight();

  // Third fight (introduction to Healing and weapon recuperation)
  Plug secondGarde("Un futur cadavre", 30, new Knife());

  MessageWriter messageWriter3(data::Level5::message3, player_->name(),
                               secondGarde.name());
  messageWriter3.writeMessage();

  if (!options_.noRule_) {
    Tutorial::write(data::Tutorial::titleNoWeapon,
                    data::Tutorial::statementNoWeapon);
  }

  Fight thirdFight(player_, {&secondGarde}, {}, options_.noRule_, false);
  thirdFight.startFight();

  MessageWriter messageWriter4(data::Level5::message4, player_->name(), "");
  messageWriter4.writeMessage();

  RegenerateAllLife regenerateAllLife(player_, Result(""));
  regenerateAllLife.triggerAction();

  MessageWriter messageWriter5(data::Level5::message5, player_->name(), "");
  messageWriter5.writeMessage();

  if (!options_.noRule_) {
    Tutorial::write(data::Tutorial::titleRegeneration,
                    data::Tutorial::statementRegeneration);
  }

  // Fourth fight
  Plug sacAPV("Sac à PV", 100, new Cutter());
  Plug kamikaze("Kamikaze", 32, new Katana());
  Plug soutien("Soutien", 60, new Knife());

  MessageWriter messageWriter6(data::Level5::message6, player_->name(),
                               kamikaze.name());
  messageWriter6.writeMessage();

  Fight fight(player_, {&sacAPV, &kamikaze, &soutien},
              {comboFistMeleeWeapon.get(), comboDoubleMeleeWeapon.get(),
               comboQuadrupleCutter.get()},
              options_.noRule_);
  fight.startFight();

  MessageWriter messageWriter7(data::Level5::message7, player_->name(), "");
  messageWriter7.writeMessage();

  regenerateAllLife.triggerAction();

  Level::endOfLevel();

  std::cout << "\n";
}