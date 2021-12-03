/*!
 * \file Level3.cpp
 */

#include "Level3.h"

#include <iostream>

#include "AddWeaponAction.h"
#include "HeaderWriter.h"
#include "Languages.h"
#include "MessageWriter.h"
#include "Selection.h"
#include "SelectionWrapper.h"
#include "UseWeapon.h"

void Level3::startLevel() {
  Plug plug("V", 100);

  Header::write(data::Level3::nameLevel, data::Level3::hour,
                data::Level3::minut);

  Message::write(data::Level3::message0, player_.name(), plug.name());

  UseWeapon useFist(player_, plug, data::Weapon::nameFist);
  useFist.triggerAction();

  Message::write(data::Level3::message1, player_.name(), plug.name());

  SelectionWrapper::select(data::Action::titleChooseWeapon, useFist);

  Message::write(data::Level3::message2(plug.name()), player_.name(),
                 plug.name());

  SelectionWrapper::select(data::Action::titleChooseWeapon, useFist);

  Message::write(data::Level3::message3, player_.name(), plug.name());

  SelectionWrapper::select(data::Action::titleChooseWeapon, useFist);

  Message::write(data::Level3::message4, player_.name(), plug.name());

  AddWeaponAction addWeaponAction(player_, weapon::Knife());
  addWeaponAction.triggerAction();

  UseWeapon useKnife(player_, plug, data::Weapon::nameKnife);

  SelectionWrapper::select(data::Action::titleChooseWeapon, useFist, useKnife);

  Message::write(data::Level3::message5, player_.name(), plug.name());

  Level::endOfLevel();

  std::cout << "\n";
}
