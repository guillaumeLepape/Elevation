#ifndef NOTHING_H
#define NOTHING_H

/*!
 * \file Nothing.h
 */

#include "NameType.h"

class Nothing {
 private:
  Statement statement_;

 public:
  Nothing(const Statement& statement) : statement_(statement) {}

  void triggerAction() {}

  const std::string& statement() const { return statement_.get(); }
};

#endif