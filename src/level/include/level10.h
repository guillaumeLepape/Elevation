#ifndef LEVEL_10_H
#define LEVEL_10_H

#include "add_weapon.h"
#include "fight.h"
#include "header_writer.h"
#include "languages.h"
#include "level_utils.h"
#include "message_writer.h"
#include "options.h"
#include "player.h"
#include "plug.h"
#include "plug_attack.h"

namespace level10 {
void start(entity::Player& player, const utils::Options& options) {
  header::write(data::level10::nameLevel, data::level10::hour,
                data::level10::minut);

  entity::Plug plug{"Dieu", 10000000, weapon::DivineStrike()};

  message::write(data::level10::messageMinus1, player.pseudo(), plug.name());

  action::AddWeapon addWeaponAction{player, weapon::AK47(100)};
  addWeaponAction.trigger();

  std::vector<MessageWriter> messageWriters{
      MessageWriter(data::level10::message0, player.pseudo(), plug.name()),
      MessageWriter(data::level10::message1, player.pseudo(), plug.name())};

  Fight fight{player,
              {&plug},
              std::vector<Combo<std::string_view>*>{},
              options.noRule_};
  fight.startFight(messageWriters, [&plug](entity::Player& player) -> bool {
    return player.healthBar().nbLifePoints() < plug.weapon().nb_damage;
  });

  message::write(data::level10::message2, player.pseudo(), plug.name());

  entity::Plug heroine{"Heroine", 100, weapon::Heroine()};
  action::PlugAttack plugAttack{player, heroine};

  while (player.healthBar().alive()) {
    plugAttack.trigger();
    message::write(data::level10::message3, player.pseudo(), "");
  }

  message::write(data::level10::message4, player.pseudo(), plug.name());
}
}  // namespace level10

#endif