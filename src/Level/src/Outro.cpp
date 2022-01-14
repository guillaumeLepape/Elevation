#include "Outro.h"

#include <iostream>

#include "HeaderWriter.h"
#include "Languages.h"
#include "LevelUtils.h"
#include "MessageWriter.h"

void Outro::start() {
  Header::write(data::Outro::nameLevel, data::Outro::hour, data::Outro::minut);

  Message::write(data::Outro::message0, player_.pseudo(), "");

  std::cout << "\n";
}