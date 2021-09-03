#ifndef CHOOSE_PLUG
#define CHOOSE_PLUG

/*!
 * \file ChoosePlug.h
 */

#include "NameType.h"

class ChoosePlug {
 private:
  const Statement& statement_;
  const Result& result_;

  Plug* const plug_;

 public:
  ChoosePlug(Plug* const plug, const Statement& statement, const Result& result)
      : statement_(statement), result_(result), plug_(plug) {}

  const std::string& statement() const { return statement_.get(); }

  void triggerAction() {}

  Plug* plug() const { return plug_; }
};

#endif