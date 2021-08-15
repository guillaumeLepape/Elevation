/*!
 * \file Level6.h
 */

#include "Level6.h"

#include <iostream>

#include "HeaderWriter.h"
#include "Languages.h"
#include "MessageWriter.h"

void Level6::startLevel() {
  HeaderWriter headerWriter(data::Level6::nameLevel, data::Level6::hour,
                            data::Level6::minut);
  headerWriter.writeHeader();

  MessageWriter messageWriter(data::Level6::message0, player_->name(), "");
  messageWriter.writeMessage();

  Level::endOfLevel();
  std::cout << "\n";
}