#ifndef PSEUDO_H
#define PSEUDO_H

/*!
 * \file Pseudo.h
 */

#include "ActionWriter.h"
#include "NameType.h"

class Player;

class Pseudo {
 private:
  Statement statement_;
  Result result_;

  Player* const player_;

  void formatString(std::string& str);

 public:
  explicit Pseudo(Player* const player, const Statement& statement,
                  const Result& result);

  void triggerAction();
};

#endif