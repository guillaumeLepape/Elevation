#ifndef OUTRO_H
#define OUTRO_H

#include "header_writer.h"
#include "languages.h"
#include "level_utils.h"
#include "message_writer.h"
#include "player.h"

namespace outro {
void start(entity::Player& player) {
  header::write(data::outro::nameLevel, data::outro::hour, data::outro::minut);

  message::write(data::outro::message0, player.pseudo(), "");

  std::cout << "\n";
}
}  // namespace outro

#endif
