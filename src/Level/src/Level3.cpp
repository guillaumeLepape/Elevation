/*!
 * \file Level3.cpp
 */

#include "Level3.h"

#include <iostream>

#include "AddWeaponAction.h"
#include "Fist.h"
#include "HeaderWriter.h"
#include "Knife.h"
#include "Languages.h"
#include "MessageWriter.h"
#include "Selection.h"
#include "UseWeapon.h"

void Level3::startLevel() {
  Plug plug("V", 100);

  Header::write(data::Level3::nameLevel, data::Level3::hour,
                data::Level3::minut);

  MessageWriter messageWriter0(data::Level3::message0, player_->name(),
                               plug.name());
  messageWriter0.writeMessage();

  const std::unique_ptr<Fist> fist(new Fist());
  std::unique_ptr<UseWeapon> useFist(new UseWeapon(
      player_, &plug, fist.get(),
      data::Weapon::resultUseWeapon(plug.name(), fist->damageWeapon())));
  useFist->triggerAction();

  MessageWriter messageWriter1(data::Level3::message1, player_->name(),
                               plug.name());
  messageWriter1.writeMessage();

  Select::select(data::Action::titleChooseWeapon, {useFist->statement()});
  useFist->triggerAction();

  auto message = data::Level3::message2(plug.name());
  MessageWriter messageWriter2(message, player_->name(), plug.name());
  messageWriter2.writeMessage();

  Select::select(data::Action::titleChooseWeapon, {useFist->statement()});
  useFist->triggerAction();

  MessageWriter messageWriter3(data::Level3::message3, player_->name(),
                               plug.name());
  messageWriter3.writeMessage();

  Select::select(data::Action::titleChooseWeapon, {useFist->statement()});
  useFist->triggerAction();

  MessageWriter messageWriter4(data::Level3::message4, player_->name(),
                               plug.name());
  messageWriter4.writeMessage();

  AddWeaponAction addWeaponAction(player_,
                                  std::unique_ptr<const Weapon>(new Knife()));
  addWeaponAction.triggerAction();

  auto knife = new Knife();
  std::unique_ptr<UseWeapon> useKnife(new UseWeapon(
      player_, &plug, knife,
      data::Weapon::resultUseWeapon(plug.name(), knife->damageWeapon())));

  auto result = Select::select(data::Action::titleChooseWeapon,
                               {useFist->statement(), useKnife->statement()});
  switch (result) {
    case 0:
      useFist->triggerAction();
      break;
    case 1:
      useKnife->triggerAction();
      break;
  }

  MessageWriter messageWriter5(data::Level3::message5, player_->name(),
                               plug.name());
  messageWriter5.writeMessage();

  Level::endOfLevel();

  std::cout << "\n";
}
