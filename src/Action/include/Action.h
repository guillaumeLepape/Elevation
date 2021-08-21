#ifndef ACTION_H
#define ACTION_H

/*!
 * \file Action.h
 */

#include "ActionWriter.h"

/*! \class Action
 * \brief Abstract class Action to introduce various actions (herited classes)
 */

class Action {
 protected:
  ActionWriter actionWriter_;
  std::string statement_;

 public:
  explicit Action(const std::string& statement, const std::string& result)
      : actionWriter_(statement, result), statement_(statement) {}

  Action(const Action& action) = delete;
  Action& operator=(const Action& action) = delete;

  const ActionWriter& actionWriter() const { return actionWriter_; }
  const std::string& statement() const { return statement_; }

  virtual void triggerAction() = 0;

  virtual ~Action() = default;
};

#endif