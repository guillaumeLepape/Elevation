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

  Message::write(data::Level3::message0, player_->name(), plug.name());

  const std::unique_ptr<Fist> fist(new Fist());
  std::unique_ptr<UseWeapon> useFist(new UseWeapon(player_, &plug, fist.get()));
  useFist->triggerAction();

  Message::write(data::Level3::message1, player_->name(), plug.name());

  Select::select(data::Action::titleChooseWeapon, {useFist->statement()});
  useFist->triggerAction();

  auto message = data::Level3::message2(plug.name());
  Message::write(message, player_->name(), plug.name());

  Select::select(data::Action::titleChooseWeapon, {useFist->statement()});
  useFist->triggerAction();

  Message::write(data::Level3::message3, player_->name(), plug.name());

  Select::select(data::Action::titleChooseWeapon, {useFist->statement()});
  useFist->triggerAction();

  Message::write(data::Level3::message4, player_->name(), plug.name());

  AddWeaponAction addWeaponAction(player_,
                                  std::unique_ptr<const Weapon>(new Knife()));
  addWeaponAction.triggerAction();

  auto knife = new Knife();
  std::unique_ptr<UseWeapon> useKnife(new UseWeapon(player_, &plug, knife));

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

  Message::write(data::Level3::message5, player_->name(), plug.name());

  Level::endOfLevel();

  std::cout << "\n";
}
