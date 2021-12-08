/*!
 * \file Dead.cpp
 */

#include "Dead.h"

#include "ActionWriter.h"
#include "Plug.h"

namespace action {
Dead::Dead(const Plug& plug, const Result& result)
    : result_(result), plug_(plug) {}

void Dead::trigger() {
  if (plug_.healthBar().dead()) {
    action::writeResult(result_);
  }
}
}  // namespace action