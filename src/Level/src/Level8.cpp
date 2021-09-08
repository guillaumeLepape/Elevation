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

  MessageWriter messageWriter0(data::Level8::message0(plug.name()),
                               player_->name(), plug.name());
  messageWriter0.writeMessage();

  AddWeaponAction addWeaponAction(player_,
                                  std::unique_ptr<const Weapon>(new Ninemm(3)));
  addWeaponAction.triggerAction();

  MessageWriter messageWriter1(data::Level8::message1, player_->name(),
                               plug.name());
  messageWriter1.writeMessage();

  Level::endOfLevel();

  std::cout << "\n";
}