#pragma once

#include "elevation/utils/concept.h"

namespace elevation::action {
template <utils::Printable T>
class Nothing {
 private:
  T statement_;

 public:
  Nothing(const T& statement) : statement_{statement} {}

  void trigger() {}

  const T& statement() const { return statement_; }
};
}  // namespace elevation::action
