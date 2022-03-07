#ifndef FIGHT_H
#define FIGHT_H

#include "Combo.h"
#include "MessageWriter.h"

struct ChooseWeaponResult {
  std::size_t resultUseWeapon;
  std::vector<action::UseWeapon> useWeapons;
};

class Fight {
 private:
  entity::Player& player_;
  std::vector<entity::Plug*> plugs_;
  std::vector<Combo*> combos_;
  bool regeneration_;

  int numberOfDeadPlug_;

  bool information_;
  bool noRule_;

  int methodNumberOfDeadPlug() const;
  bool enemiesDeadOrNot() const;

  entity::Plug& choosePlug();

  const ChooseWeaponResult chooseWeapon(entity::Plug& plug);

  void runCombos(entity::Plug& choosenPlug, int resultUseWeapon,
                 const std::vector<action::UseWeapon>& useWeapons);

 public:
  Fight(entity::Player& player, const std::vector<entity::Plug*>& plugs,
        const std::vector<Combo*>& combos, bool noRule,
        bool regeneration = true);

  void startFight(
      const std::vector<MessageWriter>& messageWriter = {},
      std::function<bool(entity::Player& player)> predicate =
          [](entity::Player& player) { return player.healthBar().dead(); });
};

#endif