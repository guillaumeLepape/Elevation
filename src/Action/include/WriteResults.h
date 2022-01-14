#ifndef WRITE_RESULTS_H
#define WRITE_RESULTS_H

#include "ActionWriter.h"
#include "NameType.h"
#include "Player.h"
#include "Results.h"

namespace action {
class WriteResults {
 private:
  Result result_;

  entity::Player& player_;
  data::Results& results_;

 public:
  WriteResults(entity::Player& player, data::Results& results,
               const Statement& statement, const Result& result);

  void trigger();
};
}  // namespace action

#endif