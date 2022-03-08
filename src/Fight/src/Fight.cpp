#include "Fight.h"

#include "AddWeaponAction.h"
#include "ChoosePlug.h"
#include "FightWriter.h"
#include "GameOver.h"
#include "InformationCombo.h"
#include "InformationWeaponInventory.h"
#include "Nothing.h"
#include "Pause.h"
#include "PlugAttack.h"
#include "Regeneration.h"
#include "Selection.h"

Fight::Fight(entity::Player& player, const std::vector<entity::Plug*>& plugs,
             const std::vector<Combo*>& combos, bool noRule, bool regeneration)
    : player_{player},
      plugs_{plugs},
      combos_{combos},
      regeneration_{regeneration},
      numberOfDeadPlug_{0},
      information_{true},
      noRule_{noRule} {}

void Fight::startFight(const std::vector<MessageWriter>& messageWriter,
                       std::function<bool(entity::Player& player)> predicate) {
  std::size_t nbTurns = 1;

  // while all enemies are not dead or player is not dead
  while ((not is_all_enemies_dead()) and (not predicate(player_)) and
         nbTurns < 1000) {
    fight::header::write(nbTurns);
    fight::game_board::write(player_, plugs_);

    // Allow player to print informations about plugs and combos
    // if the information_ is true and -r flag was selected
    if (information_ and (not noRule_)) {
      print_information();
    }

    // Choose the plug which player want to attack
    entity::Plug& choosenPlug = choosePlug();

    // Choose the weapon to attack choosenPlug
    auto [resultUseWeapon, useWeapons] = chooseWeapon(choosenPlug);

    // run the combos
    runCombos(choosenPlug, resultUseWeapon, useWeapons);

    const int countNumberOfDeadPlug = methodNumberOfDeadPlug();

    if (numberOfDeadPlug_ != countNumberOfDeadPlug) {
      numberOfDeadPlug_ = countNumberOfDeadPlug;
      action::AddWeaponAction addWeaponAction{player_,
                                              std::move(choosenPlug.weapon())};
      addWeaponAction.trigger();

      fight::remove_dead_body::write();
    }

    for (auto& plug : plugs_) {
      if (plug->healthBar().alive()) {
        auto message = data::Action::resultPlugAttack(plug->name(),
                                                      plug->weapon().nb_damage);
        action::PlugAttack plugAttack{player_, *plug, message};
        plugAttack.trigger();
      }

      if (player_.healthBar().dead()) {
        action::GameOver gameOver{data::Menu::resultGameOver};
        gameOver.trigger();
      }
    }

    // If player is not dead, regenerate her
    if (regeneration_) {
      action::Regeneration regeneration{player_, Result("")};
      regeneration.trigger();
    }

    // Check if the index is valid
    if (nbTurns - 1 < std::size(messageWriter)) {
      Message::write(messageWriter[nbTurns - 1]);
    }
  }

  fight::end::write();

  nbTurns++;
}

void Fight::print_information() {
  bool out = false;

  action::InformationWeaponInventory informationWeaponInventory{
      player_.weapons(), data::Information::statementInformationWeapon};
  action::InformationCombo informationCombo{
      combos_, data::Information::statementInformationCombo};
  action::Nothing noInformation{data::Information::statementNoInformation};
  action::Nothing noInformationAnymore{
      data::Information::statementNoInformationAnymore};

  while (not out) {
    int resultInformation = selection::select(
        data::Information::titleInformation, informationWeaponInventory,
        informationCombo, noInformation, noInformationAnymore);

    // quit loop if no information has been selected
    out = resultInformation == 2 or resultInformation == 3;

    // set info to false if noInformationAnymore selected
    information_ = resultInformation != 3;
  }
}

bool Fight::is_all_enemies_dead() const {
  return std::all_of(std::cbegin(plugs_), std::cend(plugs_),
                     [](const auto& plug) { return plug->healthBar().dead(); });
}

int Fight::methodNumberOfDeadPlug() const {
  return std::count_if(
      std::cbegin(plugs_), std::cend(plugs_),
      [](const auto& plug) { return plug->healthBar().dead(); });
}

entity::Plug& Fight::choosePlug() {
  std::vector<action::ChoosePlug> choosePlugActions;

  for (auto p = std::begin(plugs_); p != std::end(plugs_); p++) {
    // user cannot attack dead plugs
    if (((*p)->healthBar().alive())) {
      action::ChoosePlug choosePlug{
          **p, data::Action::statementChoosePlug((*p)->name()),
          data::Action::resultChoosePlug((*p)->name())};
      choosePlugActions.push_back(choosePlug);
    }
  }

  std::vector<std::string> statements;
  std::transform(std::cbegin(choosePlugActions), std::cend(choosePlugActions),
                 std::back_inserter(statements),
                 [](const auto& choosePlugAction) {
                   return choosePlugAction.statement();
                 });
  int resultChoosePlug =
      selection::select(data::Action::titleChoosePlug, statements);

  entity::Plug& choosenPlug = choosePlugActions[resultChoosePlug].plug();

  return choosenPlug;
}

const Fight::choose_weapon_result Fight::chooseWeapon(
    entity::Plug& choosenPlug) {
  std::vector<action::UseWeapon> useWeapons;

  std::transform(std::cbegin(player_.weapons()), std::cend(player_.weapons()),
                 std::back_inserter(useWeapons),
                 [this, &choosenPlug](const auto& weapon) {
                   return action::UseWeapon{player_, choosenPlug, weapon.name};
                 });

  auto resultUseWeapon =
      selection::select(data::Action::titleChooseWeapon, useWeapons);

  return {resultUseWeapon, useWeapons};
}

void Fight::runCombos(entity::Plug& choosenPlug, int resultUseWeapon,
                      const std::vector<action::UseWeapon>& useWeapons) {
  std::for_each(std::begin(combos_), std::end(combos_), [&](const auto& combo) {
    combo->triggerCombo(choosenPlug, resultUseWeapon, useWeapons);
  });
}