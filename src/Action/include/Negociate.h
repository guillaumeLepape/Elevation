#ifndef NEGOCIATE_H
#define NEGOCIATE_H

/*!
 * \file Negociate.h
 */

#include "ActionWriter.h"
#include "NameType.h"
#include "Player.h"
#include "Plug.h"

namespace action {
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

  void trigger();
};
}  // namespace action

#endif