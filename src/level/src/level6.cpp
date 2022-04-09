#include "level6.h"

#include <iostream>

#include "header_writer.h"
#include "languages.h"
#include "level_utils.h"
#include "message_writer.h"

void Level6::start() {
  header::write(data::level6::nameLevel, data::level6::hour,
                data::level6::minut);

  message::write(data::level6::message0, player_.pseudo(), "");
}