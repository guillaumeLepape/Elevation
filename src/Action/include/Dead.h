#ifndef DEAD_H
#define DEAD_H

/*!
 * \file Dead.h
 */

#include "NameType.h"
#include "Plug.h"

namespace action {
class Dead {
 private:
  Result result_;
  const Plug& plug_;

 public:
  Dead(const Plug& plug, const Result& result);

  void trigger();
};
}  // namespace action

#endif