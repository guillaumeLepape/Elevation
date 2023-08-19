#ifndef GAME_OVER_H
#define GAME_OVER_H

#include "action_writer.h"
#include "concept.h"

namespace action {
template <utils::Printable T>
class GameOver {
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

namespace game_over {
template <utils::Printable T>
void trigger(const T& result) {
  GameOver game_over{result};
  game_over.trigger();
}
}  // namespace game_over
}  // namespace action

#endif
