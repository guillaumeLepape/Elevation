#ifndef LEVEL_2_H
#define LEVEL_2_H

#include "header_writer.h"
#include "languages.h"
#include "level_utils.h"
#include "message_writer.h"
#include "negociate.h"
#include "player.h"
#include "plug.h"

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

#endif