#ifndef NEGOCIATE_H
#define NEGOCIATE_H

#include "ActionWriter.h"
#include "NameType.h"
#include "Player.h"
#include "Plug.h"

namespace action {
class Negociate {
 private:
  Statement statement_;
  Result result_;

  entity::Player& player_;
  const entity::Plug& plug_;
  int plugPrice_;

 public:
  explicit Negociate(entity::Player& player, const entity::Plug& plug,
                     int plugPrice, const Statement& statement,
                     const Result& result);

  void trigger();
};
}  // namespace action

#endif