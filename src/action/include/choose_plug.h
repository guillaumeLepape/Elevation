#ifndef CHOOSE_PLUG
#define CHOOSE_PLUG

#include "concept.h"

namespace action {
template <utils::Printable T, utils::Printable U> class ChoosePlug {
 private:
  T statement_;
  U result_;

  entity::Plug& plug_;

 public:
  ChoosePlug(entity::Plug& plug, const T& statement, const U& result)
      : statement_{statement}, result_{result}, plug_{plug} {}

  const std::string& statement() const { return statement_; }

  entity::Plug& plug() const { return plug_; }
};
}  // namespace action

#endif