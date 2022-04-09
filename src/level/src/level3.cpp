#include "level3.h"

#include <iostream>

#include "add_weapon.h"
#include "header_writer.h"
#include "languages.h"
#include "level_utils.h"
#include "message_writer.h"
#include "selection.h"
#include "use_weapon.h"

void Level3::start() {
  entity::Plug plug{"V", 100};

  header::write(data::level3::nameLevel, data::level3::hour,
                data::level3::minut);

  message::write(data::level3::message0, player_.pseudo(), plug.name());

  action::UseWeapon useFist{player_, plug, data::weapon::nameFist};
  useFist.trigger();

  message::write(data::level3::message1, player_.pseudo(), plug.name());

  selection::select(data::action::titleChooseWeapon, useFist);

  message::write(data::level3::message2(plug.name()), player_.pseudo(),
                 plug.name());

  selection::select(data::action::titleChooseWeapon, useFist);

  message::write(data::level3::message3, player_.pseudo(), plug.name());

  selection::select(data::action::titleChooseWeapon, useFist);

  message::write(data::level3::message4, player_.pseudo(), plug.name());

  action::AddWeapon addWeaponAction{player_, weapon::Knife()};
  addWeaponAction.trigger();

  action::UseWeapon useKnife{player_, plug, data::weapon::nameKnife};

  selection::select(data::action::titleChooseWeapon, useFist, useKnife);

  message::write(data::level3::message5, player_.pseudo(), plug.name());
}
