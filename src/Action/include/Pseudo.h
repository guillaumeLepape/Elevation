#ifndef PSEUDO_H
#define PSEUDO_H

/*!
 * \file Pseudo.h
 */

#include "ActionWriter.h"
#include "NameType.h"
#include "Player.h"

namespace action {
class Pseudo {
 private:
  Statement statement_;
  Result result_;

  entity::Player& player_;

  void formatString(std::string& str);

 public:
  explicit Pseudo(entity::Player& player, const Statement& statement,
                  const Result& result);

  void trigger();
};
}  // namespace action

#endif