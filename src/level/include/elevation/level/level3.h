#pragma once

#include "elevation/action/add_weapon.h"
#include "elevation/action/use_weapon.h"
#include "elevation/data_files/languages.h"
#include "elevation/entity/player.h"
#include "elevation/selection/selection.h"
#include "elevation/writer/header_writer.h"
#include "elevation/writer/message_writer.h"
#include "level_utils.h"

namespace elevation::level3 {
void start(entity::Player& player) {
  entity::Plug plug{"V", 100};

  header::write(data::level3::nameLevel, data::level3::hour,
                data::level3::minut);

  message::write(data::level3::message0, player.pseudo(), plug.name());

  action::use_weapon::trigger(player, plug, data::weapon::nameFist);

  message::write(data::level3::message1, player.pseudo(), plug.name());

  selection::select(data::action::titleChooseWeapon,
                    action::UseWeapon{player, plug, data::weapon::nameFist});

  message::write(data::level3::message2(plug.name()), player.pseudo(),
                 plug.name());

  selection::select(data::action::titleChooseWeapon,
                    action::UseWeapon{player, plug, data::weapon::nameFist});

  message::write(data::level3::message3, player.pseudo(), plug.name());

  selection::select(data::action::titleChooseWeapon,
                    action::UseWeapon{player, plug, data::weapon::nameFist});

  message::write(data::level3::message4, player.pseudo(), plug.name());

  action::add_weapon::trigger(player, weapon::Knife());

  selection::select(data::action::titleChooseWeapon,
                    action::UseWeapon{player, plug, data::weapon::nameFist},
                    action::UseWeapon{player, plug, data::weapon::nameKnife});

  message::write(data::level3::message5, player.pseudo(), plug.name());
}
}  // namespace elevation::level3
