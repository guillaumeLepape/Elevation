#ifndef LOAD_GAME_H
#define LOAD_GAME_H

#include <memory>

#include "NameType.h"
#include "Options.h"
#include "Results.h"

namespace action {
class LoadGame {
 private:
  const Statement& statement_;
  const utils::Options& options_;

 public:
  LoadGame(const Statement& statement, const utils::Options& options);

  LoadGame(const LoadGame&) = delete;
  LoadGame(LoadGame&&) = default;

  LoadGame& operator=(const LoadGame&) = delete;
  LoadGame& operator=(LoadGame&&) = default;

  ~LoadGame() = default;

  const std::string& statement() const { return statement_.get(); }

  void trigger();
};
}  // namespace action

#endif