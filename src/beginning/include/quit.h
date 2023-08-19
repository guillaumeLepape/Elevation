#ifndef QUIT_H
#define QUIT_H

#include "action_writer.h"
#include "concept.h"

namespace action {
template <utils::Printable T, utils::Printable U> class Quit {
 private:
  const T& statement_;
  const U& result_;

 public:
  Quit(const T& statement, const U& result)
      : statement_{statement}, result_{result} {}

  Quit(const Quit&) = delete;
  Quit(Quit&&) = default;

  Quit& operator=(const Quit&) = delete;
  Quit& operator=(Quit&&) = default;

  ~Quit() = default;

  const T& statement() const { return statement_; }

  void trigger() {
    result::write(result_);
    fmt::print("\n");
  }
};
}  // namespace action

#endif
