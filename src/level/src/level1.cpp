#include "level1.h"

#include <iostream>

#include "header_writer.h"
#include "languages.h"
#include "level_utils.h"
#include "message_writer.h"
#include "plug.h"

void Level1::start() {
  entity::Plug plug{"Petite frappe"};

  header::write(data::level1::nameLevel, data::level1::hour,
                data::level1::minut);

  auto price = 20;
  auto message = data::level1::message0(player_.pseudo(), plug.name(), price);

  message::write(message, player_.pseudo(), plug.name());

  player_.decreaseMoney(price);
}