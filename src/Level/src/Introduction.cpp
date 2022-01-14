#include "Introduction.h"

#include <iostream>

#include "HeaderWriter.h"
#include "Languages.h"
#include "LevelUtils.h"
#include "MessageWriter.h"
#include "Pseudo.h"

void Introduction::start() {
  Header::write(data::Introduction::nameLevel, data::Introduction::hour,
                data::Introduction::minut);

  Message::write(data::Introduction::message0, player_.pseudo(), "");

  action::Pseudo pseudo(player_, data::Action::statementPseudo,
                        data::Action::resultPseudo(player_.pseudo()));
  pseudo.trigger();

  Message::write(data::Introduction::message4(player_.pseudo()),
                 player_.pseudo(), "");

  endoflevel(player_);

  std::cout << "\n";
}