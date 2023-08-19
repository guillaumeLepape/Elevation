#ifndef SAVE_AND_QUIT_H
#define SAVE_AND_QUIT_H

#include <iostream>

#include "action_writer.h"
#include "concept.h"

namespace action {
template <utils::Printable T, utils::Printable U>
class SaveAndQuit {
 private:
  T statement_;
  U result_;

 public:
  SaveAndQuit(const T& statement, const U& result)
      : statement_(statement), result_(result) {}

  const T& statement() const { return statement_; }

  void trigger() {
    result::write(result_);
    std::cout << "\n";
    exit(0);
  }
};
}  // namespace action

#endif