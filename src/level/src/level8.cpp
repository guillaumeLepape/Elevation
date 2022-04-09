#include "level8.h"

#include <iostream>

#include "add_weapon.h"
#include "header_writer.h"
#include "languages.h"
#include "level_utils.h"
#include "message_writer.h"
#include "plug.h"

void Level8::start() {
  entity::Plug plug{"Mathilde", 30};

  header::write(data::level8::nameLevel, data::level8::hour,
                data::level8::minut);

  message::write(data::level8::message0(plug.name()), player_.pseudo(),
                 plug.name());

  action::AddWeapon addWeaponAction{player_, weapon::Ninemm(3)};
  addWeaponAction.trigger();

  message::write(data::level8::message1, player_.pseudo(), plug.name());
}