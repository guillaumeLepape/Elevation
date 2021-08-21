#ifndef QUESTION_H
#define QUESTION_H

/*!
 * \file Question.h
 */

#include <string>
#include <vector>

class Question {
 public:
  static bool question(const std::string& title,
                       const std::vector<std::string>& statements,
                       const std::vector<bool>& answers);
};

#endif