#pragma once

#include "elevation/data_files/languages.h"
#include "elevation/entity/player.h"
#include "elevation/writer/header_writer.h"
#include "elevation/writer/message_writer.h"
#include "level_utils.h"

namespace elevation::outro {
void start(entity::Player& player) {
  header::write(data::outro::nameLevel, data::outro::hour, data::outro::minut);

  message::write(data::outro::message0, player.pseudo(), "");

  std::cout << "\n";
}
}  // namespace elevation::outro
