/*!
 * \file Level3.cpp
 */

#include "Level3.h"

#include <iostream>

#include "AddWeaponAction.h"
#include "HeaderWriter.h"
#include "Languages.h"
#include "LevelUtils.h"
#include "MessageWriter.h"
#include "Selection.h"
#include "UseWeapon.h"

void Level3::start() {
  entity::Plug plug("V", 100);

  Header::write(data::Level3::nameLevel, data::Level3::hour,
                data::Level3::minut);

  Message::write(data::Level3::message0, player_.pseudo(), plug.name());

  action::UseWeapon useFist(player_, plug, data::Weapon::nameFist);
  useFist.trigger();

  Message::write(data::Level3::message1, player_.pseudo(), plug.name());

  selection::select(data::Action::titleChooseWeapon, useFist);

  Message::write(data::Level3::message2(plug.name()), player_.pseudo(),
                 plug.name());

  selection::select(data::Action::titleChooseWeapon, useFist);

  Message::write(data::Level3::message3, player_.pseudo(), plug.name());

  selection::select(data::Action::titleChooseWeapon, useFist);

  Message::write(data::Level3::message4, player_.pseudo(), plug.name());

  action::AddWeaponAction addWeaponAction(player_, weapon::Knife());
  addWeaponAction.trigger();

  action::UseWeapon useKnife(player_, plug, data::Weapon::nameKnife);

  selection::select(data::Action::titleChooseWeapon, useFist, useKnife);

  Message::write(data::Level3::message5, player_.pseudo(), plug.name());

  endoflevel(player_);

  std::cout << "\n";
}
