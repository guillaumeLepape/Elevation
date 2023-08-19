#ifndef ANSWER_H
#define ANSWER_H

#include "concept.h"

namespace action {
template <utils::Printable T>
class Answer {
 private:
  const T& statement_;
  bool correctOrNot_;

 public:
  explicit Answer(const T& statement, bool correctOrNot)
      : statement_{statement}, correctOrNot_{correctOrNot} {}

  const T& statement() const { return statement_; }

  bool correctOrNot() const { return correctOrNot_; }
};
}  // namespace action

#endif
