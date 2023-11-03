#pragma once

#include "elevation/data_files/languages.h"
#include "elevation/entity/player.h"
#include "elevation/writer/header_writer.h"
#include "elevation/writer/message_writer.h"
#include "level_utils.h"

namespace elevation::level6 {
void start(entity::Player& player) {
  header::write(data::level6::nameLevel, data::level6::hour,
                data::level6::minut);

  message::write(data::level6::message0, player.pseudo(), "");
}
}  // namespace elevation::level6
