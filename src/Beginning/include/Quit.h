#ifndef QUIT_H
#define QUIT_H

/*!
 * \file Quit.h
 */

#include "ActionWriter.h"
#include "NameType.h"

namespace action {
class Quit {
 private:
  const Statement& statement_;
  const Result& result_;

 public:
  Quit(const Statement& statement, const Result& result);

  const std::string& statement() const { return statement_.get(); }

  void trigger();
};
}  // namespace action

#endif