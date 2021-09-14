/*!
 * \file Level8.cpp
 */

#include "Level8.h"

#include <iostream>

#include "AddWeaponAction.h"
#include "HeaderWriter.h"
#include "Languages.h"
#include "MessageWriter.h"
#include "Ninemm.h"
#include "Plug.h"

void Level8::startLevel() {
  Plug plug("Mathilde", 30);

  Header::write(data::Level8::nameLevel, data::Level8::hour,
                data::Level8::minut);

  Message::write(data::Level8::message0(plug.name()), player_.name(),
                 plug.name());

  AddWeaponAction addWeaponAction(&player_,
                                  std::unique_ptr<const Weapon>(new Ninemm(3)));
  addWeaponAction.triggerAction();

  Message::write(data::Level8::message1, player_.name(), plug.name());

  Level::endOfLevel();

  std::cout << "\n";
}