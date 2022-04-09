#include "Level2.h"

#include <iostream>

#include "HeaderWriter.h"
#include "Languages.h"
#include "LevelUtils.h"
#include "MessageWriter.h"
#include "Negociate.h"
#include "Plug.h"

void Level2::start() {
  entity::Plug plug{"Jean-Luc Delarue"};

  header::write(data::level2::nameLevel, data::level2::hour,
                data::level2::minut);

  auto price = 80;
  auto message = data::level2::message0(plug.name(), price);
  message::write(message, player_.pseudo(), plug.name());

  action::Negociate negociate{player_, plug, price,
                              data::action::statementNegociate,
                              data::action::resultNegociate(0)};
  negociate.trigger();
}