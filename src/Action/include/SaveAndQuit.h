#ifndef SAVE_AND_QUIT_H
#define SAVE_AND_QUIT_H

#include <iostream>

#include "ActionWriter.h"
#include "NameType.h"

namespace action {
class SaveAndQuit {
 private:
  Statement statement_;
  Result result_;

 public:
  SaveAndQuit(const Statement& statement, const Result& result)
      : statement_(statement), result_(result) {}

  const std::string& statement() const { return statement_.get(); }

  void trigger() {
    action::writeResult(result_);
    std::cout << "\n";
    exit(0);
  }
};
}  // namespace action

#endif