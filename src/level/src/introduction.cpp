#include "introduction.h"

#include <iostream>

#include "header_writer.h"
#include "languages.h"
#include "level_utils.h"
#include "message_writer.h"
#include "pseudo.h"

void Introduction::start() {
  header::write(data::introduction::nameLevel, data::introduction::hour,
                data::introduction::minut);

  message::write(data::introduction::message0, player_.pseudo(), "");

  action::Pseudo pseudo{player_, data::action::statementPseudo,
                        data::action::resultPseudo(player_.pseudo())};
  pseudo.trigger();

  message::write(data::introduction::message4(player_.pseudo()),
                 player_.pseudo(), "");
}