#ifndef COMBO_H
#define COMBO_H

/*!
 * \file Combo.h
 */

#include "NameType.h"
#include "UseWeapon.h"

class Combo {
 protected:
  Title title_;
  std::string triggerStatement_;
  std::string triggeredStatement_;
  std::string malusStatement_;

 protected:
  Player& player_;

 public:
  Combo(Player& player, const Title& title, const std::string& triggerStatement,
        const std::string& triggeredStatement,
        const std::string& malusStatement)
      : title_(title),
        triggerStatement_(triggerStatement),
        triggeredStatement_(triggeredStatement),
        malusStatement_(malusStatement),
        player_(player) {}

  virtual void triggerCombo(Plug& plug, const int& resultChooseWeapon,
                            const std::vector<UseWeapon>& useWeapon) = 0;

  virtual ~Combo() = default;

  const std::string_view& title() const { return title_.get(); }
  const std::string& triggerStatement() const { return triggerStatement_; }
  const std::string& triggeredStatement() const { return triggeredStatement_; }
  const std::string& malusStatement() const { return malusStatement_; }
};

#endif