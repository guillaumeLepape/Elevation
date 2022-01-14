#ifndef NOTHING_H
#define NOTHING_H

#include "NameType.h"

namespace action {
class Nothing {
 private:
  Statement statement_;

 public:
  Nothing(const Statement& statement) : statement_(statement) {}

  void trigger() {}

  const std::string& statement() const { return statement_.get(); }
};
}  // namespace action

#endif