#pragma once

#include "elevation/action/negociate.h"
#include "elevation/data_files/languages.h"
#include "elevation/entity/player.h"
#include "elevation/entity/plug.h"
#include "elevation/writer/header_writer.h"
#include "elevation/writer/message_writer.h"
#include "level_utils.h"

namespace level2 {
void start(entity::Player& player) {
  entity::Plug plug{"Jean-Luc Delarue"};

  header::write(data::level2::nameLevel, data::level2::hour,
                data::level2::minut);

  auto price = 80;
  auto message = data::level2::message0(plug.name(), price);
  message::write(message, player.pseudo(), plug.name());

  action::negociate::trigger(player, plug, price,
                             data::action::statementNegociate,
                             data::action::resultNegociate(0));
}
}  // namespace level2
