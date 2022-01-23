#include "Level10.h"

#include <iostream>

#include "AddWeaponAction.h"
#include "Fight.h"
#include "HeaderWriter.h"
#include "Languages.h"
#include "LevelUtils.h"
#include "MessageWriter.h"
#include "Plug.h"
#include "PlugAttack.h"

void Level10::start() {
  Header::write(data::Level10::nameLevel, data::Level10::hour,
                data::Level10::minut);

  entity::Plug plug{"Dieu", 10000000, weapon::DivineStrike()};

  Message::write(data::Level10::messageMinus1, player_.pseudo(), plug.name());

  action::AddWeaponAction addWeaponAction{player_, weapon::AK47(100)};
  addWeaponAction.trigger();

  std::vector<MessageWriter> messageWriters{
      MessageWriter(data::Level10::message0, player_.pseudo(), plug.name()),
      MessageWriter(data::Level10::message1, player_.pseudo(), plug.name())};

  Fight fight{&player_, {&plug}, {}, options_.noRule_};
  fight.startFight(
      messageWriters, [&plug](entity::Player* const player_) -> bool {
        return player_->healthBar().nbLifePoints() < plug.weapon().nb_damage;
      });

  Message::write(data::Level10::message2, player_.pseudo(), plug.name());

  entity::Plug heroine{"Heroine", 100, weapon::Heroine()};
  action::PlugAttack plugAttack{player_, heroine, Result("")};

  while (player_.healthBar().alive()) {
    plugAttack.trigger();
    Message::write(data::Level10::message3, player_.pseudo(), "");
  }

  Message::write(data::Level10::message4, player_.pseudo(), plug.name());

  endoflevel(player_);
  std::cout << "\n";
}