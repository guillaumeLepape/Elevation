#ifndef START_GAME_H
#define START_GAME_H

#include "Concept.h"
#include "GameEngine.h"
#include "Id.h"
#include "Options.h"
#include "Results.h"

namespace action {
template <utils::Printable T> class StartGame {
 private:
  T statement_;
  const utils::Options& options_;

 public:
  StartGame(const T& statement, const utils::Options& options)
      : statement_{statement}, options_{options} {}

  StartGame(const StartGame&) = delete;
  StartGame(StartGame&&) = default;

  StartGame& operator=(const StartGame&) = delete;
  StartGame& operator=(StartGame&&) = default;

  ~StartGame() = default;

  const T& statement() const { return statement_; }

  void trigger() {
    const auto game_id = utils::id::generate();
    game_engine::launch(options_, game_id);
  }
};
}  // namespace action

#endif