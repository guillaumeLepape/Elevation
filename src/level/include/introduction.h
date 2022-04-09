#ifndef INTRODUCTION_H
#define INTRODUCTION_H

#include "header_writer.h"
#include "languages.h"
#include "level_utils.h"
#include "message_writer.h"
#include "player.h"
#include "pseudo.h"

namespace introduction {
void start(entity::Player& player) {
  header::write(data::introduction::nameLevel, data::introduction::hour,
                data::introduction::minut);

  message::write(data::introduction::message0, player.pseudo(), "");

  action::Pseudo pseudo{player, data::action::statementPseudo,
                        data::action::resultPseudo(player.pseudo())};
  pseudo.trigger();

  message::write(data::introduction::message4(player.pseudo()), player.pseudo(),
                 "");
}
}  // namespace introduction

#endif