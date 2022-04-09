#include "Level10.h"

#include <iostream>

#include "AddWeapon.h"
#include "Fight.h"
#include "HeaderWriter.h"
#include "Languages.h"
#include "LevelUtils.h"
#include "MessageWriter.h"
#include "Plug.h"
#include "PlugAttack.h"

void Level10::start() {
  header::write(data::level10::nameLevel, data::level10::hour,
                data::level10::minut);

  entity::Plug plug{"Dieu", 10000000, weapon::DivineStrike()};

  message::write(data::level10::messageMinus1, player_.pseudo(), plug.name());

  action::AddWeapon addWeaponAction{player_, weapon::AK47(100)};
  addWeaponAction.trigger();

  std::vector<MessageWriter> messageWriters{
      MessageWriter(data::level10::message0, player_.pseudo(), plug.name()),
      MessageWriter(data::level10::message1, player_.pseudo(), plug.name())};

  Fight fight{player_,
              {&plug},
              std::vector<Combo<std::string_view>*>{},
              options_.noRule_};
  fight.startFight(messageWriters, [&plug](entity::Player& player_) -> bool {
    return player_.healthBar().nbLifePoints() < plug.weapon().nb_damage;
  });

  message::write(data::level10::message2, player_.pseudo(), plug.name());

  entity::Plug heroine{"Heroine", 100, weapon::Heroine()};
  action::PlugAttack plugAttack{player_, heroine};

  while (player_.healthBar().alive()) {
    plugAttack.trigger();
    message::write(data::level10::message3, player_.pseudo(), "");
  }

  message::write(data::level10::message4, player_.pseudo(), plug.name());
}