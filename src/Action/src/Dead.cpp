/*!
 * \file Dead.cpp
 */

#include "Dead.h"

#include "Plug.h"

Dead::Dead(const Plug* const plug, const Result& result)
    : actionWriter_("", result.get()), plug_(plug) {}

void Dead::triggerAction() {
  if (plug_->dead()) {
    actionWriter_.writeResult();
  }
}