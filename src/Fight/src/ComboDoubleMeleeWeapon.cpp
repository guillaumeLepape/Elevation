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
    const std::vector<UseWeapon>& useWeapon) {
  if ((useWeapon[resultChooseWeapon].nameWeapon() == data::Weapon::nameKnife ||
       useWeapon[resultChooseWeapon].nameWeapon() ==
           data::Weapon::nameHammer) &&
      !(plug->dead())) {
    UseWeapon useWeaponCombo(player_, plug,
                             useWeapon[resultChooseWeapon].weapon());

    Nothing nothing(data::Combo::statementDontCombo);

    int result = Select::select(
        title_, {useWeaponCombo.statement(), nothing.statement()});

    switch (result) {
      case 0:
        useWeaponCombo.triggerAction();
        break;
      case 1:
        break;
    }
  }
}