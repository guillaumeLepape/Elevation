#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>

#include "AddWeapon.h"
#include "Languages.h"
#include "Player.h"
#include "Plug.h"
#include "UseWeapon.h"
#include "Weapon.h"

TEST(weapon_test, UseWeapon) {
  entity::Player player("Guillaume", 0);

  action::AddWeapon addWeaponFist(player, weapon::Fist());
  addWeaponFist.trigger();

  action::AddWeapon addWeaponAK47(player, weapon::AK47(100));
  addWeaponAK47.trigger();

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

  action::AddWeapon addWeaponFist(player, weapon::Fist());
  addWeaponFist.trigger();

  const auto& fist = *(std::cbegin(player.weapons()));

  EXPECT_EQ(fist.name, data::weapon::nameFist);
  EXPECT_EQ(fist.nb_damage, 20);
  EXPECT_EQ(fist.type, weapon::Type::fist);
  EXPECT_EQ(fist.statement, data::weapon::statementUseFist);
}

TEST(weapon_test, AK47) {
  entity::Player player("Guillaume", 0, weapon::WeaponInventory{});

  action::AddWeapon addWeaponAK47(player, weapon::AK47(40));
  addWeaponAK47.trigger();

  const auto& ak47 = *std::find_if(
      std::cbegin(player.weapons()), std::cend(player.weapons()),
      [](const auto& weapon) { return weapon.name == data::weapon::nameAK47; });

  EXPECT_EQ(ak47.nb_damage, 150);
  EXPECT_EQ(ak47.type, weapon::Type::fireArm);
  EXPECT_EQ(ak47.statement, data::weapon::statementUseAK47);
  EXPECT_EQ(ak47.durability, 40);
  EXPECT_EQ(ak47.durability_loose_per_use, 10);

  entity::Plug plug("Jean-Michel", 100);

  action::UseWeapon useAK47(player, plug, data::weapon::nameAK47);
  useAK47.trigger();

  EXPECT_EQ(ak47.nb_damage, 150);
  EXPECT_EQ(ak47.type, weapon::Type::fireArm);
  EXPECT_EQ(ak47.statement, data::weapon::statementUseAK47);
  EXPECT_EQ(ak47.durability, 30);
  EXPECT_EQ(ak47.durability_loose_per_use, 10);
}