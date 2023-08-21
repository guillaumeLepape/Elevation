#ifndef INFORMATION_COMBO_H
#define INFORMATION_COMBO_H

#include <range/v3/algorithm/for_each.hpp>

#include "combo_writer.h"
#include "concept.h"

namespace action {
template <utils::Printable T, utils::Printable U>
class InformationCombo {
 private:
  T statement_;

  std::vector<combo_v2::Combo<U>> combos_;

 public:
  InformationCombo(const std::vector<combo_v2::Combo<U>>& combos,
                   const T& statement)
      : statement_{statement}, combos_{combos} {}

  const T& statement() const { return statement_; }

  void trigger() {
    for (const auto& c : combos_) {
      combo::write(*c);
    }
  }
};
}  // namespace action

#endif
