/*!
 * \file ComboQuadrupleCutter.cpp
 */

#include "ComboQuadrupleCutter.h"

#include "Languages.h"

ComboQuadrupleCutter::ComboQuadrupleCutter(Player& player)
    : Combo(player, data::Combo::titleQuadrupleCutter,
            data::Combo::triggerStatementQuadrupleCutter,
            data::Combo::triggeredStatementQuadrupleCutter,
            data::Combo::malusStatementQuadrupleCutter) {}

void ComboQuadrupleCutter::triggerCombo(
    Plug&, const int& resultChooseWeapon,
    const std::vector<action::UseWeapon>& useWeapon) {
  if (useWeapon[resultChooseWeapon].name() == "Cutter") {
    action::UseWeapon useWeaponCombo = useWeapon[resultChooseWeapon];

    useWeaponCombo.trigger();
    useWeaponCombo.trigger();
    useWeaponCombo.trigger();
    weapon::remove(player_.weapons(), useWeapon[resultChooseWeapon].name());
  }
}