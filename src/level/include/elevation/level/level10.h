#pragma once

#include "elevation/action/add_weapon.h"
#include "elevation/action/plug_attack.h"
#include "elevation/data_files/languages.h"
#include "elevation/entity/player.h"
#include "elevation/entity/plug.h"
#include "elevation/fight/fight.h"
#include "elevation/utils/options.h"
#include "elevation/writer/header_writer.h"
#include "elevation/writer/message_writer.h"
#include "level_utils.h"

namespace elevation::level10 {
void start(entity::Player& player, const utils::Options& options) {
  header::write(data::level10::nameLevel, data::level10::hour,
                data::level10::minut);

  entity::Plug plug{"Dieu", 10000000, weapon::DivineStrike()};

  message::write(data::level10::messageMinus1, player.pseudo(), plug.name());

  action::add_weapon::trigger(player, weapon::AK47(100));

  std::vector<MessageWriter> messageWriters{
      MessageWriter(data::level10::message0, player.pseudo(), plug.name()),
      MessageWriter(data::level10::message1, player.pseudo(), plug.name())};

  fight::launch(player, {&plug},
                fight::parameters{std::vector<Combo<std::string_view>*>{},
                                  options.noRule()});

  message::write(data::level10::message2, player.pseudo(), plug.name());

  entity::Plug heroine{"Heroine", 100, weapon::Heroine()};

  while (player.healthBar().alive()) {
    action::plug_attack::trigger(player, heroine);
    message::write(data::level10::message3, player.pseudo(), "");
  }

  message::write(data::level10::message4, player.pseudo(), plug.name());
}
}  // namespace elevation::level10
