#ifndef GAME_OVER_H
#define GAME_OVER_H

#include "ActionWriter.h"
#include "Concept.h"

namespace action {
template <utils::Printable T> class GameOver {
 private:
  T result_;

 public:
  explicit GameOver(const T& result) : result_{result} {}

  void trigger() {
    result::write(result_);
    std::cout << "\n";
    exit(0);
  }
};
}  // namespace action

#endif