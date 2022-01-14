#ifndef COMBO_WRITER_H
#define COMBO_WRITER_H

#include "Combo.h"

class ComboWriter {
 private:
  const Combo* const combo_;

 public:
  ComboWriter(const Combo* const combo);

  void informationCombo() const;
};

#endif