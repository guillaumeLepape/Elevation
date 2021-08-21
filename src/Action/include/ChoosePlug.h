#ifndef CHOOSE_PLUG
#define CHOOSE_PLUG

/*!
 * \file ChoosePlug.h
 */

#include "Action.h"

class ChoosePlug : public Action {
 private:
  Plug* const plug_;

 public:
  ChoosePlug(Plug* const plug, const std::string& statement,
             const std::string& result)
      : Action(statement, result), plug_(plug) {}

  void triggerAction() override {}

  Plug* plug() const { return plug_; }
};

#endif