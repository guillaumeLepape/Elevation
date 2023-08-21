#ifndef COMBO_H
#define COMBO_H

#include <variant>

#include "concept.h"
#include "nothing.h"
#include "selection.h"
#include "use_weapon.h"

// template <utils::Printable T>
// class Combo {
//  protected:
//   T title_;
//   const T& triggerStatement_;
//   const T& triggeredStatement_;
//   const T& malusStatement_;

//  protected:
//   entity::Player& player;

//  public:
//   Combo(entity::Player& player, const T& title, const T& triggerStatement,
//         const T& triggeredStatement, const T& malusStatement)
//       : title_{title},
//         triggerStatement_{triggerStatement},
//         triggeredStatement_{triggeredStatement},
//         malusStatement_{malusStatement},
//         player{player} {}

//   virtual void triggerCombo(
//       entity::Plug& plug, int resultChooseWeapon,
//       const std::vector<action::UseWeapon>& useWeapon) = 0;

//   virtual ~Combo() = default;

//   const T& title() const { return title_; }
//   const T& triggerStatement() const { return triggerStatement_; }
//   const T& triggeredStatement() const { return triggeredStatement_; }
//   const T& malusStatement() const { return malusStatement_; }
// };

namespace combo_v2 {
struct ComboDoubleMeleeWeapon {
  ComboDoubleMeleeWeapon() : title{data::combo::titleDoubleMeleeWeapon} {}

  std::string_view title;
};

struct ComboFistMeleeWeapon {
  ComboFistMeleeWeapon() : title{data::combo::titleFistMeleeWeapon} {}

  std::string_view title;
};

struct ComboQuadrupleCutter {
  ComboQuadrupleCutter() : title{data::combo::titleQuadrupleCutter} {}

  std::string_view title;
};

using Combo = std::variant<ComboDoubleMeleeWeapon, ComboFistMeleeWeapon,
                           ComboQuadrupleCutter>;

template <class... Ts>
struct overloaded : Ts... {
  using Ts::operator()...;
};

void trigger(Combo&& combo, entity::Player& player, entity::Plug& plug,
             int resultChooseWeapon,
             const std::vector<action::UseWeapon>& useWeapon) {
  std::visit(
      overloaded{
          [&](ComboDoubleMeleeWeapon&& arg) {
            if ((useWeapon[resultChooseWeapon].name() ==
                     data::weapon::nameKnife or
                 useWeapon[resultChooseWeapon].name() ==
                     data::weapon::nameHammer) and
                plug.healthBar().alive()) {
              action::UseWeapon useWeaponCombo{
                  player, plug, useWeapon[resultChooseWeapon].name()};

              action::Nothing nothing{data::combo::statementDontCombo};

              auto result =
                  selection::select(arg.title, useWeaponCombo, nothing);
              if (result == 0) {
                weapon::remove(player.weapons(),
                               useWeapon[resultChooseWeapon].name());
              }
            }
          },
          [&](ComboFistMeleeWeapon&&) {
            // if the player has attack with his fist, trigger the combo
            // and the ennemy is not dead
            // and player has at least one melee weapon
            if (useWeapon[resultChooseWeapon].type() == weapon::Type::fist and
                plug.healthBar().alive() and
                weapon::contains(player.weapons(), weapon::Type::meleeWeapon)) {
              std::vector<action::UseWeapon> useWeaponFistCombo;

              for (auto weapon = std::cbegin(player.weapons());
                   weapon != std::cend(player.weapons()); ++weapon) {
                if (weapon->type == weapon::Type::meleeWeapon) {
                  useWeaponFistCombo.push_back(
                      action::UseWeapon{player, plug, weapon->name});
                }
              }

              selection::select(data::combo::titleFistMeleeWeapon,
                                useWeaponFistCombo);
            }
          },
          [&](ComboQuadrupleCutter&&) {
            if (useWeapon[resultChooseWeapon].name() == "Cutter") {
              action::UseWeapon useWeaponCombo = useWeapon[resultChooseWeapon];

              useWeaponCombo.trigger();
              useWeaponCombo.trigger();
              useWeaponCombo.trigger();
              weapon::remove(player.weapons(),
                             useWeapon[resultChooseWeapon].name());
            }
          }},
      std::forward<Combo>(combo));
}
}  // namespace combo_v2

#endif
