#ifndef REGENERATE_ALL_LIFE
#define REGENERATE_ALL_LIFE

/*!
 * \file RegenerateAllLife.h
 */

#include "NameType.h"

class RegenerateAllLife {
 private:
  ActionWriter actionWriter_;

  Player* const player_;

 public:
  RegenerateAllLife(Player* const player, const Result& result)
      : actionWriter_("", result.get()), player_(player) {}

  void triggerAction() {
    // if player is full life or dead, do nothing, else regenerate him
    if (!(player_->fullLife()) && !(player_->dead())) {
      actionWriter_.updateResult(
          data::Action::resultRegeneration(player_->missingLifePoints()));
      player_->increaseLifePoints(player_->missingLifePoints());
      actionWriter_.writeResult();
    }
  }
};

#endif
