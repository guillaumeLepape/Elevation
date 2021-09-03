/*!
 * \file ComboDoubleMeleeWeapon.cpp
 */

#include "ComboDoubleMeleeWeapon.h"

#include "Nothing.h"
#include "Selection.h"

ComboDoubleMeleeWeapon::ComboDoubleMeleeWeapon(Player* const player)
    : Combo(player, data::Combo::titleDoubleMeleeWeapon,
            data::Combo::triggerStatementDoubleMeleeWeapon,
            data::Combo::triggeredStatementDoubleMeleeWeapon,
            data::Combo::malusStatementDoubleMeleeWeapon) {}

void ComboDoubleMeleeWeapon::triggerCombo(
    Plug* const plug, const int& resultChooseWeapon,
    const std::vector<UseWeapon*>& useWeapon) {
  if ((useWeapon[resultChooseWeapon]->nameWeapon() == data::Weapon::nameKnife ||
       useWeapon[resultChooseWeapon]->nameWeapon() ==
           data::Weapon::nameHammer) &&
      !(plug->dead())) {
    UseWeapon useWeaponCombo(
        player_, plug, useWeapon[resultChooseWeapon]->weapon(),
        data::Weapon::resultUseWeapon(
            plug->name(),
            useWeapon[resultChooseWeapon]->weapon()->damageWeapon()));

    Nothing nothing(data::Combo::statementDontCombo);

    int result =
        Select::select(data::Combo::titleDoubleMeleeWeapon,
                       {useWeaponCombo.statement(), nothing.statement()});

    switch (result) {
      case 0:
        useWeaponCombo.triggerAction();
        break;
      case 1:
        nothing.triggerAction();
        break;
    }

    // if player choose to trigger combo, destroy the melee weapon
    if (result == 0) {
      player_->weapons()->deleteWeapon(
          useWeapon[resultChooseWeapon]->nameWeapon());
    }
  }
}