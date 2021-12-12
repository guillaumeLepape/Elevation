#ifndef CHOOSE_PLUG
#define CHOOSE_PLUG

/*!
 * \file ChoosePlug.h
 */

#include "NameType.h"

namespace action {
class ChoosePlug {
 private:
  Statement statement_;
  Result result_;

  entity::Plug& plug_;

 public:
  ChoosePlug(entity::Plug& plug, const Statement& statement,
             const Result& result)
      : statement_{statement}, result_{result}, plug_{plug} {}

  const std::string& statement() const { return statement_.get(); }

  entity::Plug& plug() const { return plug_; }
};
}  // namespace action

#endif