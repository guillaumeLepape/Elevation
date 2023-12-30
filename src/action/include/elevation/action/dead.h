#pragma once

#include "elevation/entity/plug.h"
#include "elevation/utils/concept.h"

namespace elevation::action {
template <utils::Printable U>
class Dead {
 private:
  U result_;
  const entity::Plug& plug_;
  std::istream& in_;

 public:
  Dead(const entity::Plug& plug, const U& result, std::istream& in)
      : result_{result}, plug_{plug}, in_{in} {}

  void trigger() {
    if (plug_.healthBar().dead()) {
      result::write(result_, in_);
    }
  }
};

namespace dead {
template <utils::Printable U>
void trigger(const entity::Plug& plug, const U& result, std::istream& in) {
  Dead dead{plug, result, in};
  dead.trigger();
}
}  // namespace dead
}  // namespace elevation::action
