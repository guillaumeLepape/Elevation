#include <gtest/gtest.h>

#include <iostream>
#include <algorithm>

#include "Player.h"
#include "Plug.h"
#include "Weapon.h"
#include "Fist.h"
#include "AK47.h"
#include "AddWeaponAction.h"
#include "UseWeapon.h"
#include "Languages.h"

TEST(weapon_test, UseWeapon) {
  Player player("Guillaume", 15611653, 0);

  AddWeaponAction addWeaponFist(&player, std::unique_ptr<const Weapon>(new Fist()));
  addWeaponFist.triggerAction();

  AddWeaponAction addWeaponAK47(&player, std::unique_ptr<const Weapon>(new AK47(100)));
  addWeaponAK47.triggerAction();

  EXPECT_EQ(player.name(), "Guillaume");
  EXPECT_EQ(player.id(), 15611653);

  std::vector<std::string> weaponsName;
  std::transform(
    player.weapons()->cbegin(),
    player.weapons()->cend(),
    std::back_inserter(weaponsName),
    [](const auto& weapon){ return weapon->name(); }
  );

  std::vector<std::string> expectWeaponNames = { "Poing", "AK47" };
  EXPECT_EQ(weaponsName.size(), expectWeaponNames.size());
  for ( std::size_t i = 0; i < weaponsName.size(); ++i) {
    EXPECT_EQ(weaponsName[i], expectWeaponNames[i]);
  }
}

TEST(weapon_test, Fist) {
  Player player("Guillaume", 15611653, 0, WeaponInventory{});

  AddWeaponAction addWeaponFist(&player, std::unique_ptr<const Weapon>(new Fist()));
  addWeaponFist.triggerAction();

  const auto& fist = *(player.weapons()->cbegin());

  EXPECT_EQ(fist->name(), data::Weapon::nameFist);
  EXPECT_EQ(fist->damageWeapon(), 20);
  EXPECT_EQ(fist->weaponType(), WeaponType::fist);
  EXPECT_EQ(fist->statement(), data::Weapon::statementUseFist);
}

TEST(weapon_test, AK47) {
  Player player("Guillaume", 15611653, 0, WeaponInventory{});

  AddWeaponAction addWeaponAK47(&player, std::unique_ptr<const Weapon>{new AK47{40}});
  addWeaponAK47.triggerAction();

  const auto ak47 = (*(player.weapons()->cbegin())).get();

  EXPECT_EQ(ak47->name(), data::Weapon::nameAK47);
  EXPECT_EQ(ak47->damageWeapon(), 150);
  EXPECT_EQ(ak47->weaponType(), WeaponType::fireArm);
  EXPECT_EQ(ak47->statement(), data::Weapon::statementUseAK47);
  EXPECT_EQ((static_cast<const FireArm*>(ak47))->nbAmmo(), 40);
  EXPECT_EQ((static_cast<const FireArm*>(ak47))->nbAmmoForOneShot(), 10);
} 