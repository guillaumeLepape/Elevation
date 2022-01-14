#include "Level6.h"

#include <iostream>

#include "HeaderWriter.h"
#include "Languages.h"
#include "LevelUtils.h"
#include "MessageWriter.h"

void Level6::start() {
  Header::write(data::Level6::nameLevel, data::Level6::hour,
                data::Level6::minut);

  Message::write(data::Level6::message0, player_.pseudo(), "");

  endoflevel(player_);
  std::cout << "\n";
}