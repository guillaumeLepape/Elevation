#pragma once

#include "elevation/action/action_writer.h"
#include "elevation/utils/concept.h"

namespace action {
template <utils::Printable T, utils::Printable U>
class Quit {
 private:
  const T& statement_;
  const U& result_;

 public:
  Quit(const T& statement, const U& result)
      : statement_{statement}, result_{result} {}

  Quit(const Quit&) = delete;
  Quit(Quit&&) noexcept = default;

  Quit& operator=(const Quit&) = delete;
  Quit& operator=(Quit&&) noexcept = default;

  ~Quit() noexcept = default;

  [[nodiscard]] const T& statement() const { return statement_; }

  void trigger() {
    result::write(result_);
    fmt::print("\n");
  }
};
}  // namespace action
