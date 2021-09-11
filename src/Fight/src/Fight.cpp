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
#include "Selection.h"

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
          &(player_->weapons()), data::Information::statementInformationWeapon);
      InformationCombo informationCombo(
          combos_, data::Information::statementInformationCombo);
      Nothing noInformation(data::Information::statementNoInformation);
      Nothing noInformationAnymore(
          data::Information::statementNoInformationAnymore);

      while (!out) {
        int resultInformation = Select::select(
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
    Plug* const choosenPlug = choosePlug();

    // Choose the weapon to attack choosenPlug
    ChooseWeaponResult chooseWeaponResult = chooseWeapon(choosenPlug);

    // run the combos
    runCombos(choosenPlug, chooseWeaponResult.resultUseWeapon,
              chooseWeaponResult.useWeapons);

    const int countNumberOfDeadPlug = methodNumberOfDeadPlug();

    if (numberOfDeadPlug_ != countNumberOfDeadPlug) {
      numberOfDeadPlug_ = countNumberOfDeadPlug;
      AddWeaponAction addWeaponAction(player_, choosenPlug->realeaseWeapon());
      addWeaponAction.triggerAction();

      fightWriter.writeRemoveDeadBody();
    }

    for (auto e = plugs_.begin(); e != plugs_.end(); e++) {
      if (!((*e)->dead())) {
        auto message = data::Action::resultPlugAttack(
            (*e)->name(), (*e)->weapon()->damageWeapon());
        PlugAttack plugAttack(player_, *e, message);
        plugAttack.triggerAction();
      }

      if (player_->dead()) {
        GameOver gameOver(data::Menu::resultGameOver);
        gameOver.triggerAction();
      }
    }

    // If player is not dead, regenerate her
    if (regeneration_) {
      Regeneration regeneration(player_, Result(""));
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

  for (auto e = plugs_.cbegin(); e != plugs_.cend(); e++) {
    result = result && (*e)->dead();
  }

  return result;
}

int Fight::methodNumberOfDeadPlug() const {
  int numberOfDead = 0;
  for (auto e = plugs_.cbegin(); e != plugs_.cend(); e++) {
    if ((*e)->dead()) {
      numberOfDead++;
    }
  }
  return numberOfDead;
}

Plug* Fight::choosePlug() {
  std::vector<ChoosePlug*> choosePlugActions;

  for (auto p = plugs_.begin(); p != plugs_.end(); p++) {
    // user cannot attack dead plugs
    if (!(*p)->dead()) {
      ChoosePlug* choosePlug =
          new ChoosePlug(*p, data::Action::statementChoosePlug((*p)->name()),
                         data::Action::resultChoosePlug((*p)->name()));
      choosePlugActions.push_back(choosePlug);
    }
  }

  std::vector<std::string> statements;
  std::transform(choosePlugActions.cbegin(), choosePlugActions.cend(),
                 std::back_inserter(statements),
                 [](const auto choosePlugAction) {
                   return choosePlugAction->statement();
                 });
  int resultChoosePlug =
      Select::select(data::Action::titleChoosePlug, statements);

  Plug* const choosenPlug(
      ((ChoosePlug*)choosePlugActions[resultChoosePlug])->plug());

  for (std::size_t i = 0; i < choosePlugActions.size(); i++) {
    delete choosePlugActions[i];
  }

  return choosenPlug;
}

const ChooseWeaponResult Fight::chooseWeapon(Plug* const choosenPlug) {
  std::vector<UseWeapon> useWeapons;

  for (auto w = player_->weapons().cbegin(); w != player_->weapons().cend();
       w++) {
    useWeapons.push_back(UseWeapon(player_, choosenPlug, w->get()));
  }

  std::vector<std::string> statements;
  std::transform(useWeapons.cbegin(), useWeapons.cend(),
                 std::back_inserter(statements),
                 [](const auto& useWeapon) { return useWeapon.statement(); });
  int resultUseWeapon =
      Select::select(data::Action::titleChooseWeapon, statements);
  useWeapons[resultUseWeapon].triggerAction();

  return {resultUseWeapon, useWeapons};
}

void Fight::runCombos(Plug* const choosenPlug, const int& resultUseWeapon,
                      const std::vector<UseWeapon>& useWeapons) {
  for (auto c = combos_.cbegin(); c != combos_.cend(); c++) {
    (*c)->triggerCombo(choosenPlug, resultUseWeapon, useWeapons);
  }
}