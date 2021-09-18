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
  Statement statement_;
  Result result_;

  Player& player_;
  const Plug& plug_;
  int plugPrice_;

 public:
  explicit Negociate(Player& player, const Plug& plug, const int& plugPrice,
                     const Statement& statement, const Result& result);

  void triggerAction();
};

#endif