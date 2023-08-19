#include "weapon.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>

#include "add_weapon.h"
#include "languages.h"
#include "player.h"
#include "plug.h"
#include "use_weapon.h"

TEST(weapon_test, UseWeapon) {
  entity::Player player("Guillaume", 0);

  action::add_weapon::trigger(player, weapon::Fist());

  action::add_weapon::trigger(player, weapon::AK47(100));

  EXPECT_EQ(player.pseudo(), "Guillaume");

  std::vector<std::string> weaponsName;
  std::transform(std::cbegin(player.weapons()), std::cend(player.weapons()),
                 std::back_inserter(weaponsName),
                 [](const auto& weapon) { return weapon.name; });

  std::vector<std::string> expectWeaponNames = {"Poing", "AK47"};
  EXPECT_EQ(weaponsName.size(), expectWeaponNames.size());
  for (std::size_t i = 0; i < weaponsName.size(); ++i) {
    EXPECT_EQ(weaponsName[i], expectWeaponNames[i]);
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
