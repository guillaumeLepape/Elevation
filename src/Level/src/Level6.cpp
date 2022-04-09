#include "Level6.h"

#include <iostream>

#include "HeaderWriter.h"
#include "Languages.h"
#include "LevelUtils.h"
#include "MessageWriter.h"

void Level6::start() {
  header::write(data::level6::nameLevel, data::level6::hour,
                data::level6::minut);

  message::write(data::level6::message0, player_.pseudo(), "");
}