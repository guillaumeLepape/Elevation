#ifndef LEVEL_6_H
#define LEVEL_6_H

#include "header_writer.h"
#include "languages.h"
#include "level_utils.h"
#include "message_writer.h"
#include "player.h"

namespace level6 {
void start(entity::Player& player) {
  header::write(data::level6::nameLevel, data::level6::hour,
                data::level6::minut);

  message::write(data::level6::message0, player.pseudo(), "");
}
}  // namespace level6

#endif
