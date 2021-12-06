/*!
 * \file Fight.cpp
 */

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
#include "SelectionWrapper.h"

Fight::Fight(Player* const player, const std::vector<Plug*>& plugs,
             const std::vector<Combo*>& combos, const bool& noRule,
             const bool& regeneration)
    : player_(player),
      plugs_(plugs),
      combos_(combos),
      regeneration_(regeneration),
      numberOfDeadPlug_(0),
      information_(true),
      noRule_(noRule) {}

void Fight::startFight(const std::vector<MessageWriter>& messageWriter,
                       std::function<bool(Player* const player)> predicate) {
  std::size_t nbTurns = 0;

  FightWriter fightWriter(player_, plugs_);

  // while all enemies are not dead or player is not dead
  while (!enemiesDeadOrNot() && !predicate(player_) && nbTurns < 1000) {
    nbTurns++;

    fightWriter.writeHeader(nbTurns);
    fightWriter.writeGameBoard();

    // Allow player to print informations about plugs and combos
    // if the information_ is true and -r flag was selected
    if (information_ && !noRule_) {
      bool out = false;

      InformationWeaponInventory informationWeaponInventory(
          player_->weapons(), data::Information::statementInformationWeapon);
      InformationCombo informationCombo(
          combos_, data::Information::statementInformationCombo);
      Nothing noInformation(data::Information::statementNoInformation);
      Nothing noInformationAnymore(
          data::Information::statementNoInformationAnymore);

      while (!out) {
        int resultInformation = Selection::select(
            data::Information::titleInformation,
            {informationWeaponInventory.statement(),
             informationCombo.statement(), noInformation.statement(),
             noInformationAnymore.statement()});

        switch (resultInformation) {
          case 0:
            informationWeaponInventory.triggerAction();
            break;
          case 1:
            informationCombo.triggerAction();
            break;
          case 2:
            break;
          case 3:
            break;
        }

        // If the NoInformation option have been chosen, quit the while loop
        if (resultInformation == 2) {
          out = true;
        }
        // If the NoInformationAnymore option have been chosen, quit the while
        // loop and set information_ to true not display this selection for this
        // fight
        else if (resultInformation == 3) {
          out = true;
          information_ = false;
        }
      }
    }

    // Choose the plug which player want to attack
    Plug& choosenPlug = choosePlug();

    // Choose the weapon to attack choosenPlug
    ChooseWeaponResult chooseWeaponResult = chooseWeapon(choosenPlug);

    // run the combos
    runCombos(choosenPlug, chooseWeaponResult.resultUseWeapon,
              chooseWeaponResult.useWeapons);

    const int countNumberOfDeadPlug = methodNumberOfDeadPlug();

    if (numberOfDeadPlug_ != countNumberOfDeadPlug) {
      numberOfDeadPlug_ = countNumberOfDeadPlug;
      AddWeaponAction addWeaponAction(*player_,
                                      std::move(choosenPlug.weapon()));
      addWeaponAction.triggerAction();

      fightWriter.writeRemoveDeadBody();
    }

    for (auto e = std::begin(plugs_); e != std::end(plugs_); e++) {
      if (!((*e)->healthBar().dead())) {
        auto message = data::Action::resultPlugAttack((*e)->name(),
                                                      (*e)->weapon().nb_damage);
        PlugAttack plugAttack(*player_, **e, message);
        plugAttack.triggerAction();
      }

      if (player_->healthBar().dead()) {
        GameOver gameOver(data::Menu::resultGameOver);
        gameOver.triggerAction();
      }
    }

    // If player is not dead, regenerate her
    if (regeneration_) {
      Regeneration regeneration(*player_, Result(""));
      regeneration.triggerAction();
    }

    // Check if the index is valid
    if (nbTurns - 1 < messageWriter.size()) {
      Message::write(messageWriter[nbTurns - 1]);
    }
  }

  fightWriter.writeEndOfFight();

  std::cout << "\n";
}

bool Fight::enemiesDeadOrNot() const {
  bool result = true;

  for (auto e = std::cbegin(plugs_); e != std::cend(plugs_); e++) {
    result = result && (*e)->healthBar().dead();
  }

  return result;
}

int Fight::methodNumberOfDeadPlug() const {
  int numberOfDead = 0;
  for (auto e = std::cbegin(plugs_); e != std::cend(plugs_); e++) {
    if ((*e)->healthBar().dead()) {
      numberOfDead++;
    }
  }
  return numberOfDead;
}

Plug& Fight::choosePlug() {
  std::vector<ChoosePlug> choosePlugActions;

  for (auto p = std::begin(plugs_); p != std::end(plugs_); p++) {
    // user cannot attack dead plugs
    if (!((*p)->healthBar().dead())) {
      ChoosePlug choosePlug(**p,
                            data::Action::statementChoosePlug((*p)->name()),
                            data::Action::resultChoosePlug((*p)->name()));
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
      Selection::select(data::Action::titleChoosePlug, statements);

  Plug& choosenPlug = choosePlugActions[resultChoosePlug].plug();

  return choosenPlug;
}

const ChooseWeaponResult Fight::chooseWeapon(Plug& choosenPlug) {
  std::vector<UseWeapon> useWeapons;

  std::transform(std::cbegin(player_->weapons()), std::cend(player_->weapons()),
                 std::back_inserter(useWeapons),
                 [this, &choosenPlug](const auto& weapon) {
                   return UseWeapon(*player_, choosenPlug, weapon.name);
                 });

  auto resultUseWeapon =
      SelectionWrapper::select(data::Action::titleChooseWeapon, useWeapons);

  return {resultUseWeapon, useWeapons};
}

void Fight::runCombos(Plug& choosenPlug, const int& resultUseWeapon,
                      const std::vector<UseWeapon>& useWeapons) {
  for (auto c = std::cbegin(combos_); c != std::cend(combos_); c++) {
    (*c)->triggerCombo(choosenPlug, resultUseWeapon, useWeapons);
  }
}