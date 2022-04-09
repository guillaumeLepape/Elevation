#include "Outro.h"

#include <iostream>

#include "HeaderWriter.h"
#include "Languages.h"
#include "LevelUtils.h"
#include "MessageWriter.h"

void Outro::start() {
  header::write(data::outro::nameLevel, data::outro::hour, data::outro::minut);

  message::write(data::outro::message0, player_.pseudo(), "");

  std::cout << "\n";
}