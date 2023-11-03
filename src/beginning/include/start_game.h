#pragma once

#include "concept.h"
#include "game_engine.h"
#include "id.h"
#include "options.h"
#include "results.h"

namespace action {
template <utils::Printable T>
class StartGame {
 private:
  T statement_;
  const utils::Options& options_;

 public:
  StartGame(const T& statement, const utils::Options& options)
      : statement_{statement}, options_{options} {}

  StartGame(const StartGame&) = delete;
  StartGame(StartGame&&) noexcept = default;

  StartGame& operator=(const StartGame&) = delete;
  StartGame& operator=(StartGame&&) noexcept = default;

  ~StartGame() noexcept = default;

  [[nodiscard]] const T& statement() const { return statement_; }

  void trigger() { game_engine::launch(options_, utils::id::generate()); }
};
}  // namespace action
