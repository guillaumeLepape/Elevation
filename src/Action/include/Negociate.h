#ifndef NEGOCIATE_H
#define NEGOCIATE_H

/*!
 * \file Negociate.h
 */

#include "ActionWriter.h"
#include "NameType.h"

class Player;
class Plug;

class Negociate {
 private:
  const Statement& statement_;
  const Result& result_;

  Player* const player_;
  Plug* const plug_;
  int plugPrice_;

 public:
  explicit Negociate(Player* const player, Plug* const plug,
                     const int& plugPrice, const Statement& statement,
                     const Result& result);

  void triggerAction();
};

#endif