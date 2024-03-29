#pragma once

#include <range/v3/algorithm/for_each.hpp>

#include "elevation/fight/combo_writer.h"
#include "elevation/utils/concept.h"

namespace elevation::action {
template <utils::Printable T, utils::Printable U>
class InformationCombo {
 private:
  T statement_;

  std::vector<Combo<U>*> combos_;

 public:
  InformationCombo(const std::vector<Combo<U>*>& combos, const T& statement)
      : statement_{statement}, combos_{combos} {}

  const T& statement() const { return statement_; }

  void trigger() {
    for (const auto& c : combos_) {
      combo::write(*c);
    }
  }
};
}  // namespace elevation::action
