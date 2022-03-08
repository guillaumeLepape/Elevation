#ifndef FIGHT_H
#define FIGHT_H

#include "AddWeaponAction.h"
#include "Combo.h"
#include "FightWriter.h"
#include "GameOver.h"
#include "MessageWriter.h"
#include "PlugAttack.h"
#include "Regeneration.h"

class Fight {
 private:
  entity::Player& player_;
  std::vector<entity::Plug*> plugs_;
  std::vector<Combo*> combos_;
  bool regeneration_;

  int numberOfDeadPlug_;

  bool information_;
  bool noRule_;

  void print_information();

  int methodNumberOfDeadPlug() const;
  bool is_all_enemies_dead() const;

  entity::Plug& choosePlug();

  using choose_weapon_result =
      std::pair<std::size_t, std::vector<action::UseWeapon>>;
  const choose_weapon_result chooseWeapon(entity::Plug& plug);

  void runCombos(entity::Plug& choosenPlug, int resultUseWeapon,
                 const std::vector<action::UseWeapon>& useWeapons);

  static constexpr auto default_stop_condition = [](entity::Player& player) {
    return player.healthBar().dead();
  };

 public:
  Fight(entity::Player& player, const std::vector<entity::Plug*>& plugs,
        const std::vector<Combo*>& combos, bool noRule,
        bool regeneration = true);

  template <typename T = decltype(default_stop_condition)>
  requires std::predicate<T, entity::Player&> void startFight(
      const std::vector<MessageWriter>& messageWriter = {},
      T stop_condition = default_stop_condition) {
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
          auto message = data::Action::resultPlugAttack(
              plug->name(), plug->weapon().nb_damage);
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
};

#endif