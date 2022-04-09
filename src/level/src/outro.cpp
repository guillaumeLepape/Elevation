#include "outro.h"

#include <iostream>

#include "header_writer.h"
#include "languages.h"
#include "level_utils.h"
#include "message_writer.h"

void Outro::start() {
  header::write(data::outro::nameLevel, data::outro::hour, data::outro::minut);

  message::write(data::outro::message0, player_.pseudo(), "");

  std::cout << "\n";
}