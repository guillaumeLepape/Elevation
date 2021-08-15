#ifndef QUESTION_H
#define QUESTION_H

/*!
 * \file Question.h
 */

#include <vector>

#include "Answer.h"

class Question {
 public:
  static bool question(const std::vector<Answer*>& answers,
                       const std::string& title);
};

#endif