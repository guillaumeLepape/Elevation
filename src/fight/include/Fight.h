#ifndef FIGHT_H
#define FIGHT_H

#include <range/v3/algorithm/all_of.hpp>
#include <range/v3/algorithm/count_if.hpp>
#include <range/v3/algorithm/for_each.hpp>

#include "AddWeaponAction.h"
#include "ChoosePlug.h"
#include "Combo.h"
#include "FightWriter.h"
#include "GameOver.h"
#include "InformationCombo.h"
#include "InformationWeaponInventory.h"
#include "MessageWriter.h"
#include "Nothing.h"
#include "Pause.h"
#include "PlugAttack.h"
#include "Regeneration.h"
#include "Selection.h"

template <utils::Printable T> class Fight {
 private:
  entity::Player& player_;
  std::vector<entity::Plug*> plugs_;
  std::vector<Combo<T>*> combos_;
  bool regeneration_;

  int numberOfDeadPlug_;

  bool information_;
  bool noRule_;

  void print_information() {
    bool out = false;

    action::InformationWeaponInventory informationWeaponInventory{
        player_.weapons(), data::information::statementInformationWeapon};
    action::InformationCombo informationCombo{
        combos_, data::information::statementInformationCombo};
    action::Nothing noInformation{data::information::statementNoInformation};
    action::Nothing noInformationAnymore{
        data::information::statementNoInformationAnymore};

    while (not out) {
      auto resultInformation = selection::select(
          data::information::titleInformation, informationWeaponInventory,
          informationCombo, noInformation, noInformationAnymore);

      // quit loop if no information has been selected
      out = resultInformation == 2 or resultInformation == 3;

      // set info to false if noInformationAnymore selected
      information_ = resultInformation != 3;
    }
  }

  int methodNumberOfDeadPlug() const {
    return ranges::count_if(
        plugs_, [](const auto& plug) { return plug->healthBar().dead(); });
  }
  bool is_all_enemies_dead() const {
    return ranges::all_of(
        plugs_, [](const auto& plug) { return plug->healthBar().dead(); });
  }

  entity::Plug& choosePlug() {
    std::vector<action::ChoosePlug<std::string, std::string>> choosePlugActions;

    for (auto p = std::begin(plugs_); p != std::end(plugs_); p++) {
      // user cannot attack dead plugs
      if (((*p)->healthBar().alive())) {
        action::ChoosePlug choosePlug{
            **p, data::action::statementChoosePlug((*p)->name()),
            data::action::resultChoosePlug((*p)->name())};
        choosePlugActions.push_back(choosePlug);
      }
    }

    std::vector<std::string> statements;
    std::transform(std::cbegin(choosePlugActions), std::cend(choosePlugActions),
                   std::back_inserter(statements),
                   [](const auto& choosePlugAction) {
                     return choosePlugAction.statement();
                   });
    int resultChoosePlug = selection::select_from_statement(
        data::action::titleChoosePlug, statements);

    entity::Plug& choosenPlug = choosePlugActions[resultChoosePlug].plug();

    return choosenPlug;
  }

  using choose_weapon_result =
      std::pair<std::size_t, std::vector<action::UseWeapon>>;
  const choose_weapon_result chooseWeapon(entity::Plug& choosenPlug) {
    std::vector<action::UseWeapon> useWeapons;

    std::transform(
        std::cbegin(player_.weapons()), std::cend(player_.weapons()),
        std::back_inserter(useWeapons),
        [this, &choosenPlug](const auto& weapon) {
          return action::UseWeapon{player_, choosenPlug, weapon.name};
        });

    auto resultUseWeapon =
        selection::select(data::action::titleChooseWeapon, useWeapons);

    return {resultUseWeapon, useWeapons};
  }

  void runCombos(entity::Plug& choosenPlug, int resultUseWeapon,
                 const std::vector<action::UseWeapon>& useWeapons) {
    ranges::for_each(combos_, [&](const auto& combo) {
      combo->triggerCombo(choosenPlug, resultUseWeapon, useWeapons);
    });
  }

 public:
  static constexpr auto default_stop_condition = [](entity::Player& player) {
    return player.healthBar().dead();
  };

 public:
  Fight(entity::Player& player, const std::vector<entity::Plug*>& plugs,
        const std::vector<Combo<T>*>& combos, bool noRule,
        bool regeneration = true)
      : player_{player},
        plugs_{plugs},
        combos_{combos},
        regeneration_{regeneration},
        numberOfDeadPlug_{0},
        information_{true},
        noRule_{noRule} {}

  template <typename U = decltype(default_stop_condition)>
  requires std::predicate<U, entity::Player&> void startFight(
      const std::vector<MessageWriter>& messageWriter = {},
      U stop_condition = default_stop_condition) {
    std::size_t nbTurns = 1;

    // while all enemies are not dead or player is not dead
    while ((not is_all_enemies_dead()) and (not stop_condition(player_)) and
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
        action::AddWeaponAction addWeaponAction{
            player_, std::move(choosenPlug.weapon())};
        addWeaponAction.trigger();

        fight::remove_dead_body::write();
      }

      for (auto& plug : plugs_) {
        if (plug->healthBar().alive()) {
          action::PlugAttack plugAttack{player_, *plug};
          plugAttack.trigger();
        }

        if (player_.healthBar().dead()) {
          action::GameOver gameOver{data::menu::resultGameOver};
          gameOver.trigger();
        }
      }

      // If player is not dead, regenerate her
      if (regeneration_) {
        action::Regeneration regeneration{player_};
        regeneration.trigger();
      }

      // Check if the index is valid
      if (nbTurns - 1 < std::size(messageWriter)) {
        message::write(messageWriter[nbTurns - 1]);
      }
    }

    fight::end::write();

    nbTurns++;
  }
};

namespace fight {
template <utils::Printable T,
          typename U = decltype(Fight<T>::default_stop_condition)>
requires std::predicate<U, entity::Player&> struct parameters {
  const std::vector<Combo<T>*>& combos;
  bool noRule;
  bool regeneration = true;
  const std::vector<MessageWriter>& messageWriter = {};
  U stop_condition = Fight<T>::default_stop_condition;
};

template <utils::Printable T,
          typename U = decltype(Fight<T>::default_stop_condition)>
requires std::predicate<U, entity::Player&> void launch(
    entity::Player& player, const std::vector<entity::Plug*>& plugs,
    const parameters<T, U>& params) {
  Fight fight(player, plugs, params.combos, params.noRule, params.regeneration);

  fight.startFight(params.messageWriter, params.stop_condition);
}
}  // namespace fight

#endif