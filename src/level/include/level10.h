#ifndef LEVEL_10_H
#define LEVEL_10_H

#include "add_weapon.h"
#include "fight.h"
#include "header_writer.h"
#include "languages.h"
#include "level_utils.h"
#include "message_writer.h"
#include "options.h"
#include "player.h"
#include "plug.h"
#include "plug_attack.h"

namespace level10 {
void start(entity::Player& player, const utils::Options& options) {
  header::write(data::level10::nameLevel, data::level10::hour,
                data::level10::minut);

  entity::Plug plug{"Dieu", 10000000, weapon::DivineStrike()};

  message::write(data::level10::messageMinus1, player.pseudo(), plug.name());

  action::add_weapon::trigger(player, weapon::AK47(100));

  std::vector<MessageWriter> messageWriters{
      MessageWriter(data::level10::message0, player.pseudo(), plug.name()),
      MessageWriter(data::level10::message1, player.pseudo(), plug.name())};

  fight::launch(
      player, {&plug},
      fight::parameters{std::vector<combo_v2::Combo>{}, options.noRule});

  message::write(data::level10::message2, player.pseudo(), plug.name());

  entity::Plug heroine{"Heroine", 100, weapon::Heroine()};

  while (player.healthBar().alive()) {
    action::plug_attack::trigger(player, heroine);
    message::write(data::level10::message3, player.pseudo(), "");
  }

  message::write(data::level10::message4, player.pseudo(), plug.name());
}
}  // namespace level10

#endif
