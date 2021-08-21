#ifndef NEGOCIATE_H
#define NEGOCIATE_H

/*!
 * \file Negociate.h
 */

#include "Action.h"

class Player;
class Plug;

class Negociate : public Action {
 private:
  Player* const player_;
  Plug* const plug_;
  int plugPrice_;

 public:
  explicit Negociate(Player* const player, Plug* const plug,
                     const int& plugPrice, const std::string& statement,
                     const std::string& result);

  void triggerAction() override;
};

#endif