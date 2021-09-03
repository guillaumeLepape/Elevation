#ifndef ANSWER_H
#define ANSWER_H

/*!
 * \file Answer.h
 */

#include "AnswerWriter.h"
#include "NameType.h"

class Answer {
 private:
  const Statement& statement_;

  const AnswerWriter answerWriter_;

 public:
  explicit Answer(const Statement& statement, const bool& correctOrNot)
      : statement_(statement),
        answerWriter_(statement.get(), "", correctOrNot) {}

  const std::string& statement() const { return statement_.get(); }

  void triggerAction() {}

  const bool& correctOrNot() const { return answerWriter_.correctOrNot(); }
};

#endif