#include "Level8.h"

#include <iostream>

#include "AddWeaponAction.h"
#include "HeaderWriter.h"
#include "Languages.h"
#include "LevelUtils.h"
#include "MessageWriter.h"
#include "Plug.h"

void Level8::start() {
  entity::Plug plug{"Mathilde", 30};

  header::write(data::level8::nameLevel, data::level8::hour,
                data::level8::minut);

  message::write(data::level8::message0(plug.name()), player_.pseudo(),
                 plug.name());

  action::AddWeaponAction addWeaponAction{player_, weapon::Ninemm(3)};
  addWeaponAction.trigger();

  message::write(data::level8::message1, player_.pseudo(), plug.name());
}