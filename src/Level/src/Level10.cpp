/*!
 * \file Level10.cpp
 */

#include "Level10.h"

#include <iostream>

#include "AK47.h"
#include "AddWeaponAction.h"
#include "DivineStrike.h"
#include "Fight.h"
#include "HeaderWriter.h"
#include "Heroine.h"
#include "Languages.h"
#include "MessageWriter.h"
#include "Plug.h"
#include "PlugAttack.h"

void Level10::startLevel() {
  Header::write(data::Level10::nameLevel, data::Level10::hour,
                data::Level10::minut);

  Plug plug("Dieu", 10000000,
            std::unique_ptr<const Weapon>(new DivineStrike()));

  Message::write(data::Level10::messageMinus1, player_.name(), plug.name());

  AddWeaponAction addWeaponAction(player_,
                                  std::unique_ptr<const Weapon>(new AK47(100)));
  addWeaponAction.triggerAction();

  std::vector<MessageWriter> messageWriters;
  messageWriters.push_back(
      MessageWriter(data::Level10::message0, player_.name(), plug.name()));
  messageWriters.push_back(
      MessageWriter(data::Level10::message1, player_.name(), plug.name()));

  Fight fight(&player_, {&plug}, {}, options_.noRule_);
  fight.startFight(messageWriters, [&plug](Player* const player_) -> bool {
    return player_->nbLifePoints() < plug.weapon()->damageWeapon();
  });

  Message::write(data::Level10::message2, player_.name(), plug.name());

  Plug heroine("Heroine", 100, std::unique_ptr<const Weapon>(new Heroine()));
  PlugAttack plugAttack(player_, heroine, Result(""));

  while (!(player_.dead())) {
    plugAttack.triggerAction();
    Message::write(data::Level10::message3, player_.name(), "");
  }

  Message::write(data::Level10::message4, player_.name(), plug.name());

  Level::endOfLevel();
  std::cout << "\n";
}