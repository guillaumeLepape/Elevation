#ifndef COMBO_H
#define COMBO_H

#include "NameType.h"
#include "UseWeapon.h"

class Combo {
 protected:
  Title title_;
  const TriggerStatement& triggerStatement_;
  const TriggeredStatement& triggeredStatement_;
  const MalusStatement& malusStatement_;

 protected:
  entity::Player& player_;

 public:
  Combo(entity::Player& player, const Title& title,
        const TriggerStatement& triggerStatement,
        const TriggeredStatement& triggeredStatement,
        const MalusStatement& malusStatement)
      : title_{title},
        triggerStatement_{triggerStatement},
        triggeredStatement_{triggeredStatement},
        malusStatement_{malusStatement},
        player_{player} {}

  virtual void triggerCombo(
      entity::Plug& plug, const int& resultChooseWeapon,
      const std::vector<action::UseWeapon>& useWeapon) = 0;

  virtual ~Combo() = default;

  const std::string_view& title() const { return title_.get(); }
  const std::string_view& triggerStatement() const {
    return triggerStatement_.get();
  }
  const std::string_view& triggeredStatement() const {
    return triggeredStatement_.get();
  }
  const std::string_view& malusStatement() const {
    return malusStatement_.get();
  }
};

#endif