/*!
 * \file ComboDoubleMeleeWeapon.cpp
 */

#include "ComboDoubleMeleeWeapon.h"

#include "Nothing.h"
#include "SelectionWrapper.h"

ComboDoubleMeleeWeapon::ComboDoubleMeleeWeapon(Player& player)
    : Combo(player, data::Combo::titleDoubleMeleeWeapon,
            data::Combo::triggerStatementDoubleMeleeWeapon,
            data::Combo::triggeredStatementDoubleMeleeWeapon,
            data::Combo::malusStatementDoubleMeleeWeapon) {}

void ComboDoubleMeleeWeapon::triggerCombo(
    Plug& plug, const int& resultChooseWeapon,
    const std::vector<UseWeapon>& useWeapon) {
  if ((useWeapon[resultChooseWeapon].name() == data::Weapon::nameKnife ||
       useWeapon[resultChooseWeapon].name() == data::Weapon::nameHammer) &&
      !(plug.dead())) {
    UseWeapon useWeaponCombo(player_, plug,
                             useWeapon[resultChooseWeapon].name());

    Nothing nothing(data::Combo::statementDontCombo);

    int result = SelectionWrapper::select(title_, useWeaponCombo, nothing);
    if (result == 0) {
      player_.weapons().deleteWeapon(useWeapon[resultChooseWeapon].name());
    }
  }
}