#ifndef PSEUDO_H
#define PSEUDO_H

/*!
 * \file Pseudo.h
 */

#include "Action.h"

class Player;

class Pseudo : public Action {
 private:
  Player* const player_;

  void formatString(std::string& str);

 public:
  explicit Pseudo(Player* const player, const std::string& statement,
                  const std::string& result);

  void triggerAction() override;
};

#endif