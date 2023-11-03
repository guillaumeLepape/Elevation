#pragma once

#include "elevation/action/pseudo.h"
#include "elevation/data_files/languages.h"
#include "elevation/entity/player.h"
#include "elevation/writer/header_writer.h"
#include "elevation/writer/message_writer.h"
#include "level_utils.h"

namespace elevation::introduction {
void start(entity::Player& player) {
  header::write(data::introduction::nameLevel, data::introduction::hour,
                data::introduction::minut);

  message::write(data::introduction::message0, player.pseudo(), "");

  action::pseudo::trigger(player, data::action::statementPseudo,
                          data::action::resultPseudo(player.pseudo()));

  message::write(data::introduction::message4(player.pseudo()), player.pseudo(),
                 "");
}
}  // namespace elevation::introduction
