/*!
 * \file Question.cpp
 */

#include "Question.h"

#include "Selection.h"

bool Question::question(const std::string& title,
                        const std::vector<std::string>& statements,
                        const std::vector<bool>& answers) {
  int result = Select::select(title, statements);
  return answers[result];
}