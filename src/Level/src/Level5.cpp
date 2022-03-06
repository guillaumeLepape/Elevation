#include "Level5.h"

#include <iostream>

#include "ComboDoubleMeleeWeapon.h"
#include "ComboFistMeleeWeapon.h"
#include "ComboQuadrupleCutter.h"
#include "Fight.h"
#include "HeaderWriter.h"
#include "Languages.h"
#include "LevelUtils.h"
#include "MessageWriter.h"
#include "RegenerateAllLife.h"
#include "TutorialWriter.h"

void Level5::start() {
  Header::write(data::Level5::nameLevel, data::Level5::hour,
                data::Level5::minut);

  entity::Plug guetteur{"Guetteur", 35, weapon::Fist()};

  Message::write(data::Level5::message0, player_.pseudo(), guetteur.name());

  Message::write(data::Level5::message1, player_.pseudo(), guetteur.name());

  if (not options_.noRule_) {
    Tutorial::write(data::Tutorial::titleCombatSystem,
                    data::Tutorial::statementCombatSystem(
                        player_.healthBar().maxLifePoints()));
    Tutorial::write(data::Tutorial::titleCombo, data::Tutorial::statementCombo);
  }

  // Declare combos
  std::unique_ptr<Combo> comboFistMeleeWeapon{
      new ComboFistMeleeWeapon(player_)};
  std::unique_ptr<Combo> comboDoubleMeleeWeapon{
      new ComboDoubleMeleeWeapon(player_)};
  std::unique_ptr<Combo> comboQuadrupleCutter{
      new ComboQuadrupleCutter(player_)};

  // First fight (introduction to Fist - Melee Weapon combo)
  if (not options_.noRule_) {
    Tutorial::write(data::Tutorial::titleComboFistMeleeWeapon,
                    data::Tutorial::statementComboFistMeleeWeapon);
  }

  Fight firstFight{&player_,
                   {&guetteur},
                   {comboFistMeleeWeapon.get()},
                   options_.noRule_,
                   false};
  firstFight.startFight();

  // Second fight (introduction to Double melee Weapon combo )
  entity::Plug garde{"Garde", 50, weapon::Fist()};

  Message::write(data::Level5::message2, player_.pseudo(), garde.name());

  if (not options_.noRule_) {
    Tutorial::write(data::Tutorial::titleComboDoubleMeleeWeapon,
                    data::Tutorial::statementComboDoubleMeleeWeapon);
  }

  Fight secondFight{&player_,
                    {&garde},
                    {comboDoubleMeleeWeapon.get()},
                    options_.noRule_,
                    false};
  secondFight.startFight();

  // Third fight (introduction to Healing and weapon recuperation)
  entity::Plug secondGarde{"Un futur cadavre", 30, weapon::Knife()};

  Message::write(data::Level5::message3, player_.pseudo(), secondGarde.name());

  if (not options_.noRule_) {
    Tutorial::write(data::Tutorial::titleNoWeapon,
                    data::Tutorial::statementNoWeapon);
  }

  Fight thirdFight{&player_, {&secondGarde}, {}, options_.noRule_, false};
  thirdFight.startFight();

  Message::write(data::Level5::message4, player_.pseudo(), "");

  action::RegenerateAllLife regenerateAllLife{player_, Result("")};
  regenerateAllLife.trigger();

  Message::write(data::Level5::message5, player_.pseudo(), "");

  if (not options_.noRule_) {
    Tutorial::write(data::Tutorial::titleRegeneration,
                    data::Tutorial::statementRegeneration);
  }

  // Fourth fight
  entity::Plug sacAPV{"Sac à PV", 100, weapon::Cutter()};
  entity::Plug kamikaze{"Kamikaze", 32, weapon::Katana()};
  entity::Plug soutien{"Soutien", 60, weapon::Knife()};

  Message::write(data::Level5::message6, player_.pseudo(), kamikaze.name());

  Fight fight{&player_,
              {&sacAPV, &kamikaze, &soutien},
              {comboFistMeleeWeapon.get(), comboDoubleMeleeWeapon.get(),
               comboQuadrupleCutter.get()},
              options_.noRule_};
  fight.startFight();

  Message::write(data::Level5::message7, player_.pseudo(), "");

  regenerateAllLife.trigger();
}