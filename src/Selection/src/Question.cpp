/*!
 * \file Question.cpp
 */

#include "Question.h"

#include "Selection.h"

namespace Question {
bool question(const Title& title, const std::vector<std::string>& statements,
              const std::vector<bool>& answers) {
  std::size_t result = Selection::select(title, statements);
  return answers[result];
}
}  // namespace Question