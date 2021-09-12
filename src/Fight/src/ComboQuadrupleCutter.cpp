/*!
 * \file ComboQuadrupleCutter.cpp
 */

#include "ComboQuadrupleCutter.h"

#include "Languages.h"

ComboQuadrupleCutter::ComboQuadrupleCutter(Player* const player)
    : Combo(player, data::Combo::titleQuadrupleCutter,
            data::Combo::triggerStatementQuadrupleCutter,
            data::Combo::triggeredStatementQuadrupleCutter,
            data::Combo::malusStatementQuadrupleCutter) {}

void ComboQuadrupleCutter::triggerCombo(
    Plug* const plug, const int& resultChooseWeapon,
    const std::vector<UseWeapon>& useWeapon) {
  if (useWeapon[resultChooseWeapon].name() == "Cutter") {
    UseWeapon useWeaponCombo = useWeapon[resultChooseWeapon];

    useWeaponCombo.triggerAction();
    useWeaponCombo.triggerAction();
    useWeaponCombo.triggerAction();
    player_->weapons().deleteWeapon(useWeapon[resultChooseWeapon].name());
  }
}