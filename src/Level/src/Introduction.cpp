/*!
 * \file Introduction.cpp
 */

#include "Introduction.h"

#include <iostream>

#include "HeaderWriter.h"
#include "Languages.h"
#include "MessageWriter.h"
#include "Pseudo.h"

void Introduction::startLevel() {
  Header::write(data::Introduction::nameLevel, data::Introduction::hour,
                data::Introduction::minut);

  Message::write(data::Introduction::message0, player_.pseudo(), "");

  action::Pseudo pseudo(player_, data::Action::statementPseudo,
                        data::Action::resultPseudo(player_.pseudo()));
  pseudo.trigger();

  Message::write(data::Introduction::message4(player_.pseudo()),
                 player_.pseudo(), "");

  Level::endOfLevel();

  std::cout << "\n";
}