#ifndef INFORMATION_COMBO_H
#define INFORMATION_COMBO_H

/*!
 * \file InformationCombo.h
 */

#include "ComboWriter.h"
#include "NameType.h"

class InformationCombo {
 private:
  Statement statement_;

  std::vector<Combo*> combos_;

 public:
  InformationCombo(const std::vector<Combo*>& combos,
                   const Statement& statement)
      : statement_(statement), combos_(combos) {}

  const std::string& statement() const { return statement_.get(); }

  void triggerAction() {
    for (long unsigned int i = 0; i < combos_.size(); i++) {
      ComboWriter comboWriter(combos_[i]);
      comboWriter.informationCombo();
    }
  }
};

#endif