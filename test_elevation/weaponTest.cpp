#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>

#include "AddWeaponAction.h"
#include "Languages.h"
#include "Player.h"
#include "Plug.h"
#include "UseWeapon.h"
#include "Weapon.h"

TEST(weapon_test, UseWeapon) {
  Player player("Guillaume", 15611653, 0);

  AddWeaponAction addWeaponFist(player, weapon::Fist());
  addWeaponFist.triggerAction();

  AddWeaponAction addWeaponAK47(player, weapon::AK47(100));
  addWeaponAK47.triggerAction();

  EXPECT_EQ(player.name(), "Guillaume");
  EXPECT_EQ(player.id(), 15611653);

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
  Player player("Guillaume", 15611653, 0, weapon::WeaponInventory{});

  AddWeaponAction addWeaponFist(player, weapon::Fist());
  addWeaponFist.triggerAction();

  const auto& fist = *(std::cbegin(player.weapons()));

  EXPECT_EQ(fist.name, data::Weapon::nameFist);
  EXPECT_EQ(fist.nb_damage, 20);
  EXPECT_EQ(fist.type, weapon::Type::fist);
  EXPECT_EQ(fist.statement, data::Weapon::statementUseFist);
}

TEST(weapon_test, AK47) {
  Player player("Guillaume", 15611653, 0, weapon::WeaponInventory{});

  AddWeaponAction addWeaponAK47(player, weapon::AK47(40));
  addWeaponAK47.triggerAction();

  for (const auto& weapon : player.weapons()) {
    if (weapon.name == data::Weapon::nameAK47) {
      EXPECT_EQ(weapon.nb_damage, 150);
      EXPECT_EQ(weapon.type, weapon::Type::fireArm);
      EXPECT_EQ(weapon.statement, data::Weapon::statementUseAK47);
      EXPECT_EQ(weapon.durability, 40);
      EXPECT_EQ(weapon.durability_loose_per_use, 10);
    }
  }

  Plug plug("Jean-Michel", 100);

  UseWeapon useAK47(player, plug, data::Weapon::nameAK47);
  useAK47.triggerAction();

  for (const auto& weapon : player.weapons()) {
    if (weapon.name == data::Weapon::nameAK47) {
      EXPECT_EQ(weapon.nb_damage, 150);
      EXPECT_EQ(weapon.type, weapon::Type::fireArm);
      EXPECT_EQ(weapon.statement, data::Weapon::statementUseAK47);
      EXPECT_EQ(weapon.durability, 30);
      EXPECT_EQ(weapon.durability_loose_per_use, 10);
    }
  }
}