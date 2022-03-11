#ifndef INFORMATION_COMBO_H
#define INFORMATION_COMBO_H

#include <range/v3/algorithm/for_each.hpp>

#include "ComboWriter.h"
#include "NameType.h"

namespace action {
class InformationCombo {
 private:
  Statement statement_;

  std::vector<Combo*> combos_;

 public:
  InformationCombo(const std::vector<Combo*>& combos,
                   const Statement& statement)
      : statement_{statement}, combos_{combos} {}

  const std::string& statement() const { return statement_.get(); }

  void trigger() {
    ranges::for_each(combos_, [](const Combo* combo) {
      ComboWriter comboWriter{combo};
      comboWriter.informationCombo();
    });
  }
};
}  // namespace action

#endif