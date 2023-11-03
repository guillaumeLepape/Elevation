#pragma once

#include "elevation/data_files/languages.h"
#include "elevation/entity/player.h"
#include "elevation/entity/plug.h"
#include "elevation/writer/header_writer.h"
#include "elevation/writer/message_writer.h"
#include "level_utils.h"

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
