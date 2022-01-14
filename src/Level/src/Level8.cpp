/*!
 * \file Level8.cpp
 */

#include "Level8.h"

#include <iostream>

#include "AddWeaponAction.h"
#include "HeaderWriter.h"
#include "Languages.h"
#include "LevelUtils.h"
#include "MessageWriter.h"
#include "Plug.h"

void Level8::start() {
  entity::Plug plug("Mathilde", 30);

  Header::write(data::Level8::nameLevel, data::Level8::hour,
                data::Level8::minut);

  Message::write(data::Level8::message0(plug.name()), player_.pseudo(),
                 plug.name());

  action::AddWeaponAction addWeaponAction(player_, weapon::Ninemm(3));
  addWeaponAction.trigger();

  Message::write(data::Level8::message1, player_.pseudo(), plug.name());

  endoflevel(player_);

  std::cout << "\n";
}