/*!
 * \file Level1.cpp
 */

#include "Level1.h"

#include <iostream>

#include "HeaderWriter.h"
#include "Languages.h"
#include "MessageWriter.h"
#include "Plug.h"

void Level1::startLevel() {
  Plug plug("Petite frappe");

  Header::write(data::Level1::nameLevel, data::Level1::hour,
                data::Level1::minut);

  int price = 20;
  auto message = data::Level1::message0(player_->name(), plug.name(), price);

  MessageWriter messageWriter(message, player_->name(), plug.name());
  messageWriter.writeMessage();

  player_->decreaseMoney(price);

  Level::endOfLevel();

  std::cout << "\n";
}