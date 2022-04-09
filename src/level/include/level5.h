#ifndef LEVEL_5_H
#define LEVEL_5_H

#include "combo_double_melee_weapon.h"
#include "combo_fist_melee_weapon.h"
#include "combo_quadruple_cutter.h"
#include "fight.h"
#include "header_writer.h"
#include "languages.h"
#include "level_utils.h"
#include "message_writer.h"
#include "options.h"
#include "player.h"
#include "regenerate_all_life.h"
#include "tutorial_writer.h"

namespace level5 {
void start(entity::Player& player, const utils::Options& options) {
  header::write(data::level5::nameLevel, data::level5::hour,
                data::level5::minut);

  entity::Plug guetteur{"Guetteur", 35, weapon::Fist()};

  message::write(data::level5::message0, player.pseudo(), guetteur.name());

  message::write(data::level5::message1, player.pseudo(), guetteur.name());

  if (not options.noRule_) {
    tutorial::write(data::tutorial::titleCombatSystem,
                    data::tutorial::statementCombatSystem(
                        player.healthBar().maxLifePoints()));
    tutorial::write(data::tutorial::titleCombo, data::tutorial::statementCombo);
  }

  // Declare combos
  std::unique_ptr<Combo<std::string_view>> comboFistMeleeWeapon{
      new ComboFistMeleeWeapon<std::string_view>(player)};
  std::unique_ptr<Combo<std::string_view>> comboDoubleMeleeWeapon{
      new ComboDoubleMeleeWeapon<std::string_view>(player)};
  std::unique_ptr<Combo<std::string_view>> comboQuadrupleCutter{
      new ComboQuadrupleCutter<std::string_view>(player)};

  // First fight (introduction to Fist - Melee Weapon combo)
  if (not options.noRule_) {
    tutorial::write(data::tutorial::titleComboFistMeleeWeapon,
                    data::tutorial::statementComboFistMeleeWeapon);
  }

  fight::parameters parameters_1{
      std::vector<Combo<std::string_view>*>{comboFistMeleeWeapon.get()},
      options.noRule_, false};

  fight::launch(player, std::vector{&guetteur}, parameters_1);

  // Fight firstFight{
  //     player_, {&guetteur}, parameters};
  // firstFight.startFight();

  // Second fight (introduction to Double melee Weapon combo )
  entity::Plug garde{"Garde", 50, weapon::Fist()};

  message::write(data::level5::message2, player.pseudo(), garde.name());

  if (not options.noRule_) {
    tutorial::write(data::tutorial::titleComboDoubleMeleeWeapon,
                    data::tutorial::statementComboDoubleMeleeWeapon);
  }

  fight::parameters parameters_2{
      std::vector<Combo<std::string_view>*>{comboDoubleMeleeWeapon.get()},
      options.noRule_, false};

  fight::launch(player, std::vector{&garde}, parameters_2);

  // Fight secondFight{
  //     player_, {&garde}, {comboDoubleMeleeWeapon}, options.noRule_, false};
  // secondFight.startFight();

  // Third fight (introduction to Healing and weapon recuperation)
  entity::Plug secondGarde{"Un futur cadavre", 30, weapon::Knife()};

  message::write(data::level5::message3, player.pseudo(), secondGarde.name());

  if (not options.noRule_) {
    tutorial::write(data::tutorial::titleNoWeapon,
                    data::tutorial::statementNoWeapon);
  }

  fight::parameters parameters_3{std::vector<Combo<std::string_view>*>{},
                                 options.noRule_, false};
  fight::launch(player, std::vector{&secondGarde}, parameters_3);
  // Fight thirdFight{player_, {&secondGarde}, {}, options.noRule_, false};
  // thirdFight.startFight();

  message::write(data::level5::message4, player.pseudo(), "");

  action::RegenerateAllLife regenerateAllLife{player};
  regenerateAllLife.trigger();

  message::write(data::level5::message5, player.pseudo(), "");

  if (not options.noRule_) {
    tutorial::write(data::tutorial::titleRegeneration,
                    data::tutorial::statementRegeneration);
  }

  // Fourth fight
  entity::Plug sacAPV{"Sac à PV", 100, weapon::Cutter()};
  entity::Plug kamikaze{"Kamikaze", 32, weapon::Katana()};
  entity::Plug soutien{"Soutien", 60, weapon::Knife()};

  message::write(data::level5::message6, player.pseudo(), kamikaze.name());

  fight::parameters parameters_4{
      std::vector<Combo<std::string_view>*>{comboFistMeleeWeapon.get(),
                                            comboDoubleMeleeWeapon.get(),
                                            comboQuadrupleCutter.get()},
      options.noRule_};
  fight::launch(player, std::vector{&sacAPV, &kamikaze, &soutien},
                parameters_4);

  // Fight fight{
  //     player_,
  //     {&sacAPV, &kamikaze, &soutien},
  //     {comboFistMeleeWeapon, comboDoubleMeleeWeapon, comboQuadrupleCutter},
  //     options.noRule_};
  // fight.startFight();

  message::write(data::level5::message7, player.pseudo(), "");

  regenerateAllLife.trigger();
}
}  // namespace level5

#endif