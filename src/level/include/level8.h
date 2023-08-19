#ifndef LEVEL_8_H
#define LEVEL_8_H

#include "add_weapon.h"
#include "header_writer.h"
#include "languages.h"
#include "level_utils.h"
#include "message_writer.h"
#include "player.h"
#include "plug.h"

namespace level8 {
void start(entity::Player& player) {
  entity::Plug plug{"Mathilde", 30};

  header::write(data::level8::nameLevel, data::level8::hour,
                data::level8::minut);

  message::write(data::level8::message0(plug.name()), player.pseudo(),
                 plug.name());

  action::add_weapon::trigger(player, weapon::Ninemm(3));

  message::write(data::level8::message1, player.pseudo(), plug.name());
}
}  // namespace level8

#endif
