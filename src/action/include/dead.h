#ifndef DEAD_H
#define DEAD_H

#include "concept.h"
#include "plug.h"

namespace action {
template <utils::Printable U>
class Dead {
 private:
  U result_;
  const entity::Plug& plug_;

 public:
  Dead(const entity::Plug& plug, const U& result)
      : result_{result}, plug_{plug} {}

  void trigger() {
    if (plug_.healthBar().dead()) {
      result::write(result_);
    }
  }
};

namespace dead {
template <utils::Printable U>
void trigger(const entity::Plug& plug, const U& result) {
  Dead dead{plug, result};
  dead.trigger();
}
}  // namespace dead
}  // namespace action

#endif