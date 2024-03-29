#include "elevation/weapon/weapon.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <range/v3/view.hpp>

#include "elevation/action/add_weapon.h"
#include "elevation/action/use_weapon.h"
#include "elevation/data_files/languages.h"
#include "elevation/entity/player.h"
#include "elevation/entity/plug.h"

namespace elevation {
TEST(weapon_test, UseWeapon) {
  entity::Player player("Guillaume", 0);

  action::add_weapon::trigger(player, weapon::Fist());

  action::add_weapon::trigger(player, weapon::AK47(100));

  EXPECT_EQ(player.pseudo(), "Guillaume");

  std::vector<std::string> expectWeaponNames = {"Poing", "AK47"};

  EXPECT_EQ(player.weapons().size(), expectWeaponNames.size());

  for (const auto& [playerWeapon, expectWeaponName] :
       ranges::views::zip(player.weapons(), expectWeaponNames)) {
    EXPECT_EQ(playerWeapon.name, expectWeaponName);
  }
}

TEST(weapon_test, Fist) {
  entity::Player player("Guillaume", 0, weapon::WeaponInventory{});

  action::add_weapon::trigger(player, weapon::Fist());

  const auto& fist = *(std::cbegin(player.weapons()));

  EXPECT_EQ(fist.name, data::weapon::nameFist);
  EXPECT_EQ(fist.nb_damage, 20);
  EXPECT_EQ(fist.type, weapon::Type::fist);
  EXPECT_EQ(fist.statement, data::weapon::statementUseFist);
}

TEST(weapon_test, AK47) {
  entity::Player player("Guillaume", 0, weapon::WeaponInventory{});

  action::add_weapon::trigger(player, weapon::AK47(40));

  const auto& ak47 = *std::find_if(
      std::cbegin(player.weapons()), std::cend(player.weapons()),
      [](const auto& weapon) { return weapon.name == data::weapon::nameAK47; });

  EXPECT_EQ(ak47.nb_damage, 150);
  EXPECT_EQ(ak47.type, weapon::Type::fireArm);
  EXPECT_EQ(ak47.statement, data::weapon::statementUseAK47);
  EXPECT_EQ(ak47.durability, 40);
  EXPECT_EQ(ak47.durability_loose_per_use, 10);

  entity::Plug plug("Jean-Michel", 100);

  action::use_weapon::trigger(player, plug, data::weapon::nameAK47);

  EXPECT_EQ(ak47.nb_damage, 150);
  EXPECT_EQ(ak47.type, weapon::Type::fireArm);
  EXPECT_EQ(ak47.statement, data::weapon::statementUseAK47);
  EXPECT_EQ(ak47.durability, 30);
  EXPECT_EQ(ak47.durability_loose_per_use, 10);
}
}  // namespace elevation
