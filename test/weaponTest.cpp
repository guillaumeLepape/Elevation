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
  entity::Player player("Guillaume", 15611653, 0);

  action::AddWeaponAction addWeaponFist(player, weapon::Fist());
  addWeaponFist.trigger();

  action::AddWeaponAction addWeaponAK47(player, weapon::AK47(100));
  addWeaponAK47.trigger();

  EXPECT_EQ(player.pseudo(), "Guillaume");
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
  entity::Player player("Guillaume", 15611653, 0, weapon::WeaponInventory{});

  action::AddWeaponAction addWeaponFist(player, weapon::Fist());
  addWeaponFist.trigger();

  const auto& fist = *(std::cbegin(player.weapons()));

  EXPECT_EQ(fist.name, data::Weapon::nameFist);
  EXPECT_EQ(fist.nb_damage, 20);
  EXPECT_EQ(fist.type, weapon::Type::fist);
  EXPECT_EQ(fist.statement, data::Weapon::statementUseFist);
}

TEST(weapon_test, AK47) {
  entity::Player player("Guillaume", 15611653, 0, weapon::WeaponInventory{});

  action::AddWeaponAction addWeaponAK47(player, weapon::AK47(40));
  addWeaponAK47.trigger();

  for (const auto& weapon : player.weapons()) {
    if (weapon.name == data::Weapon::nameAK47) {
      EXPECT_EQ(weapon.nb_damage, 150);
      EXPECT_EQ(weapon.type, weapon::Type::fireArm);
      EXPECT_EQ(weapon.statement, data::Weapon::statementUseAK47);
      EXPECT_EQ(weapon.durability, 40);
      EXPECT_EQ(weapon.durability_loose_per_use, 10);
    }
  }

  entity::Plug plug("Jean-Michel", 100);

  action::UseWeapon useAK47(player, plug, data::Weapon::nameAK47);
  useAK47.trigger();

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