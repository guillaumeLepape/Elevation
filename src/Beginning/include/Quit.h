#ifndef QUIT_H
#define QUIT_H

#include "ActionWriter.h"
#include "NameType.h"

namespace action {
class Quit {
 private:
  const Statement& statement_;
  const Result& result_;

 public:
  Quit(const Statement& statement, const Result& result);

  Quit(const Quit&) = delete;
  Quit(Quit&&) = default;

  Quit& operator=(const Quit&) = delete;
  Quit& operator=(Quit&&) = default;

  ~Quit() = default;

  const std::string& statement() const { return statement_.get(); }

  void trigger();
};
}  // namespace action

#endif