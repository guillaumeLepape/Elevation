#ifndef INFORMATION_COMBO_H
#define INFORMATION_COMBO_H

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
    std::for_each(std::cbegin(combos_), std::cend(combos_),
                  [](const Combo* combo) {
                    ComboWriter comboWriter{combo};
                    comboWriter.informationCombo();
                  });
  }
};
}  // namespace action

#endif