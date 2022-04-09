#ifndef NOTHING_H
#define NOTHING_H

#include "concept.h"

namespace action {
template <utils::Printable T> class Nothing {
 private:
  T statement_;

 public:
  Nothing(const T& statement) : statement_{statement} {}

  void trigger() {}

  const T& statement() const { return statement_; }
};
}  // namespace action

#endif