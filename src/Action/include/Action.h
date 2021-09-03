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

  Action(const Action&) = delete;
  Action(Action&&) = default;

  Action& operator=(const Action&) = delete;
  Action& operator=(Action&&) = default;

  virtual void triggerAction() = 0;

  virtual ~Action() = default;
};

#endif