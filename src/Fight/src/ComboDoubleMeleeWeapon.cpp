/*!
 * \file ComboDoubleMeleeWeapon.cpp
 */

#include "ComboDoubleMeleeWeapon.h"

#include "Nothing.h"
#include "Selection.h"

ComboDoubleMeleeWeapon::ComboDoubleMeleeWeapon(entity::Player& player)
    : Combo{player, data::Combo::titleDoubleMeleeWeapon,
            data::Combo::triggerStatementDoubleMeleeWeapon,
            data::Combo::triggeredStatementDoubleMeleeWeapon,
            data::Combo::malusStatementDoubleMeleeWeapon} {}

void ComboDoubleMeleeWeapon::triggerCombo(
    entity::Plug& plug, const int& resultChooseWeapon,
    const std::vector<action::UseWeapon>& useWeapon) {
  if ((useWeapon[resultChooseWeapon].name() == data::Weapon::nameKnife or
       useWeapon[resultChooseWeapon].name() == data::Weapon::nameHammer) and
      plug.healthBar().alive()) {
    action::UseWeapon useWeaponCombo(player_, plug,
                                     useWeapon[resultChooseWeapon].name());

    action::Nothing nothing(data::Combo::statementDontCombo);

    int result = selection::select(title_, useWeaponCombo, nothing);
    if (result == 0) {
      weapon::remove(player_.weapons(), useWeapon[resultChooseWeapon].name());
    }
  }
}