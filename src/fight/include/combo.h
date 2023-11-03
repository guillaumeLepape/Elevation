#pragma once

#include <variant>

#include "concept.h"
#include "nothing.h"
#include "selection.h"
#include "use_weapon.h"

template <utils::Printable T>
class Combo {
 protected:
  T title_;
  const T& triggerStatement_;
  const T& triggeredStatement_;
  const T& malusStatement_;

 protected:
  entity::Player& player_;

 public:
  Combo(entity::Player& player, const T& title, const T& triggerStatement,
        const T& triggeredStatement, const T& malusStatement)
      : title_{title},
        triggerStatement_{triggerStatement},
        triggeredStatement_{triggeredStatement},
        malusStatement_{malusStatement},
        player_{player} {}

  virtual void triggerCombo(entity::Plug& plug,
                            action::UseWeapon& useWeapon) = 0;

  virtual ~Combo() = default;

  const T& title() const { return title_; }
  const T& triggerStatement() const { return triggerStatement_; }
  const T& triggeredStatement() const { return triggeredStatement_; }
  const T& malusStatement() const { return malusStatement_; }
};

namespace combo_v2 {
template <typename T>
struct ComboDoubleMeleeWeapon {
  T title = data::combo::titleDoubleMeleeWeapon;
};
template <typename T>
struct ComboFistMeleeWeapon {
  T title = data::combo::titleFistMeleeWeapon;
};
template <typename T>
struct ComboQuadrupleCutter {
  T title = data::combo::titleQuadrupleCutter;
};

template <typename T>
using Combo = std::variant<ComboDoubleMeleeWeapon<T>, ComboFistMeleeWeapon<T>,
                           ComboQuadrupleCutter<T>>;

template <class... Ts>
struct overloaded : Ts... {
  using Ts::operator()...;
};

template <typename T>
void trigger(Combo<T>&& combo, entity::Player& player, entity::Plug& plug,
             int resultChooseWeapon,
             const std::vector<action::UseWeapon>& useWeapon) {
  std::visit(
      overloaded{
          [&](ComboDoubleMeleeWeapon<T>&& arg) {
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
          [&](ComboFistMeleeWeapon<T>&& arg) {
            // if the player has attack with his fist, trigger the combo
            // and the ennemy is not dead
            // and player has at least one melee weapon
            if (useWeapon[resultChooseWeapon].type() == weapon::Type::fist and
                plug.healthBar().alive() and
                weapon::contains(Combo<T>::player_.weapons(),
                                 weapon::Type::meleeWeapon)) {
              std::vector<action::UseWeapon> useWeaponFistCombo;

              for (auto weapon = std::cbegin(Combo<T>::player_.weapons());
                   weapon != std::cend(Combo<T>::player_.weapons()); ++weapon) {
                if (weapon->type == weapon::Type::meleeWeapon) {
                  useWeaponFistCombo.push_back(
                      action::UseWeapon{Combo<T>::player_, plug, weapon->name});
                }
              }

              selection::select(Combo<T>::title_, useWeaponFistCombo);
            }
          },
          [&](ComboQuadrupleCutter<T>&& arg) {
            if (useWeapon[resultChooseWeapon].name() == "Cutter") {
              action::UseWeapon useWeaponCombo = useWeapon[resultChooseWeapon];

              useWeaponCombo.trigger();
              useWeaponCombo.trigger();
              useWeaponCombo.trigger();
              weapon::remove(Combo<T>::player_.weapons(),
                             useWeapon[resultChooseWeapon].name());
            }
          }},
      combo);
}
}  // namespace combo_v2
