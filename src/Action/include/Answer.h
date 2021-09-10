#ifndef ANSWER_H
#define ANSWER_H

/*!
 * \file Answer.h
 */

#include "NameType.h"

class Answer {
 private:
  const Statement& statement_;
  bool correctOrNot_;

 public:
  explicit Answer(const Statement& statement, const bool& correctOrNot)
      : statement_(statement), correctOrNot_(correctOrNot) {}

  const std::string& statement() const { return statement_.get(); }

  const bool& correctOrNot() const { return correctOrNot_; }
};

#endif