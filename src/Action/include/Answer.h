#ifndef ANSWER_H
#define ANSWER_H

/*!
 * \file Answer.h
 */

#include "Action.h"
#include "AnswerWriter.h"

class Answer : public Action {
 private:
  const AnswerWriter answerWriter_;

 public:
  explicit Answer(const std::string& statement, const std::string& result,
                  const bool& correctOrNot)
      : Action(statement, result),
        answerWriter_(statement, result, correctOrNot) {}

  void triggerAction() override {}

  const bool& correctOrNot() const { return answerWriter_.correctOrNot(); }
};

#endif