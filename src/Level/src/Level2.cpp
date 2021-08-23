/*!
 * \file Level2.cpp
 */

#include "Level2.h"

#include <iostream>

#include "HeaderWriter.h"
#include "Languages.h"
#include "MessageWriter.h"
#include "Negociate.h"
#include "Plug.h"

void Level2::startLevel() {
  Plug plug("Jean-Luc Delarue");

  Header::write(data::Level2::nameLevel, data::Level2::hour,
                data::Level2::minut);

  int price = 80;
  auto message = data::Level2::message0(plug.name(), price);
  MessageWriter messageWriter(message, player_->name(), plug.name());
  messageWriter.writeMessage();

  Negociate negociate(player_, &plug, price, data::Action::statementNegociate,
                      data::Action::resultNegociate(0));
  negociate.triggerAction();

  Level::endOfLevel();

  std::cout << "\n";
}