#ifndef COMBO_DOUBLE_MELEE_WEAPON
#define COMBO_DOUBLE_MELEE_WEAPON

#include "combo.h"
#include "nothing.h"
#include "selection.h"
#include "use_weapon.h"

template <utils::Printable T> class ComboDoubleMeleeWeapon : public Combo<T> {
 public:
  ComboDoubleMeleeWeapon(entity::Player& player)
      : Combo<T>{player, data::combo::titleDoubleMeleeWeapon,
                 data::combo::triggerStatementDoubleMeleeWeapon,
                 data::combo::triggeredStatementDoubleMeleeWeapon,
                 data::combo::malusStatementDoubleMeleeWeapon} {}

  void triggerCombo(entity::Plug& plug, int resultChooseWeapon,
                    const std::vector<action::UseWeapon>& useWeapon) override {
    if ((useWeapon[resultChooseWeapon].name() == data::weapon::nameKnife or
         useWeapon[resultChooseWeapon].name() == data::weapon::nameHammer) and
        plug.healthBar().alive()) {
      auto result = selection::select(
          Combo<T>::title_,
          action::UseWeapon{Combo<T>::player_, plug,
                            useWeapon[resultChooseWeapon].name()},
          action::Nothing{data::combo::statementDontCombo});
      if (result == 0) {
        weapon::remove(Combo<T>::player_.weapons(),
                       useWeapon[resultChooseWeapon].name());
      }
    }
  }

  ~ComboDoubleMeleeWeapon() override = default;
};

#endif