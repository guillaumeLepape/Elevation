#pragma once

#include "elevation/action/add_weapon.h"
#include "elevation/data_files/languages.h"
#include "elevation/entity/player.h"
#include "elevation/entity/plug.h"
#include "elevation/writer/header_writer.h"
#include "elevation/writer/message_writer.h"
#include "level_utils.h"

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
