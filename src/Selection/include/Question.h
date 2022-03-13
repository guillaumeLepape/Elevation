#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>

#include "Concept.h"
#include "Selection.h"

namespace selection {
template <utils::Printable T, utils::Printable U>
bool question(T&& title, const std::vector<U>& statements,
              const std::vector<bool>& answers) {
  std::size_t result =
      selection::select_from_statement(std::forward<T>(title), statements);
  return answers[result];
}
}  // namespace selection

#endif