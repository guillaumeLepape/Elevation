/*!
 * \file Outro.cpp
 */

#include "Outro.h"

#include <iostream>

#include "HeaderWriter.h"
#include "Languages.h"
#include "MessageWriter.h"

void Outro::startLevel() {
  Header::write(data::Outro::nameLevel, data::Outro::hour, data::Outro::minut);

  Message::write(data::Outro::message0, player_->name(), "");

  std::cout << "\n";
}