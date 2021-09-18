/*!
 * \file Dead.cpp
 */

#include "Dead.h"

#include "ActionWriter.h"
#include "Plug.h"

Dead::Dead(const Plug& plug, const Result& result)
    : result_(result), plug_(plug) {}

void Dead::triggerAction() {
  if (plug_.dead()) {
    Action::writeResult(result_);
  }
}