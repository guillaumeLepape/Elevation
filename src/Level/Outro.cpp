/*!
 * \file Outro.cpp
 */

#include "Outro.h"

#include <iostream>

#include "HeaderWriter.h"
#include "Languages.h"
#include "MessageWriter.h"

void Outro::startLevel() {
  HeaderWriter headerWriter(data::Outro::nameLevel, data::Outro::hour,
                            data::Outro::minut);
  headerWriter.writeHeader();

  MessageWriter messageWriter(data::Outro::message0, player_->name(), "");
  messageWriter.writeMessage();

  std::cout << "\n";
}