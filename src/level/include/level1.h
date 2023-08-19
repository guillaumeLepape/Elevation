#ifndef LEVEL_1_H
#define LEVEL_1_H

#include "header_writer.h"
#include "languages.h"
#include "level_utils.h"
#include "message_writer.h"
#include "player.h"
#include "plug.h"

namespace level1 {
void start(entity::Player& player) {
  entity::Plug plug{"Petite frappe"};

  header::write(data::level1::nameLevel, data::level1::hour,
                data::level1::minut);

  auto price = 20;
  auto message = data::level1::message0(player.pseudo(), plug.name(), price);

  message::write(message, player.pseudo(), plug.name());

  player.decreaseMoney(price);
}
}  // namespace level1

#endif
