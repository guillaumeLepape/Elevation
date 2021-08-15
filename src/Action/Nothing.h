#ifndef NOTHING_H
#define NOTHING_H

/*!
 * \file Nothing.h
 */

#include "Action.h"

class Nothing : public Action {
 public:
  Nothing(const std::string& statement, const std::string& result)
      : Action(statement, result) {}

  void triggerAction() override {}
};

#endif