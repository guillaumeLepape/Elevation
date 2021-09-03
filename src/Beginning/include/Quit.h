#ifndef QUIT_H
#define QUIT_H

/*!
 * \file Quit.h
 */

#include "ActionWriter.h"
#include "NameType.h"

class Quit {
 private:
  const Statement& statement_;

  ActionWriter actionWriter_;

 public:
  Quit(const Statement& statement, const Result& result);

  const std::string& statement() const { return statement_.get(); }

  void triggerAction();
};

#endif