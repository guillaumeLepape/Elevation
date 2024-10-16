#pragma once

#include "elevation/action/action_writer.h"
#include "elevation/data_files/languages.h"
#include "elevation/entity/player.h"
#include "elevation/entity/plug.h"
#include "elevation/utils/concept.h"
#include "elevation/utils/pause.h"
#include "elevation/writer/message_writer.h"

namespace elevation::action {
template <utils::Printable T, utils::Printable U>
class Negociate {
 private:
  T statement_;
  U result_;

  entity::Player& player_;
  const entity::Plug& plug_;
  int plugPrice_;

 public:
  explicit Negociate(entity::Player& player, const entity::Plug& plug,
                     int plugPrice, const T& statement, const U& result)
      : statement_{statement},
        result_{result},
        player_{player},
        plug_{plug},
        plugPrice_{plugPrice} {}

  void trigger() {
    bool out = false;

    message::write(data::level2::message1, player_.pseudo(), plug_.name());

    while (not out) {
      statement::write(statement_);

      int price;
      std::cin >> price;

      while (true) {
        if (std::cin.fail()) {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

          fmt::print("\n ");
          fmt::print(bg(fmt::color::red) | fmt::emphasis::bold,
                     "Entrez le prix valide.");

          utils::pause();

          statement::write(statement_);
          std::cin >> price;
        }
        if (not std::cin.fail()) {
          break;
        }
      }

      if (price > plugPrice_) {
        message::write(data::level2::message2, player_.pseudo(), plug_.name());
      } else if (price <= plugPrice_ and plugPrice_ - 30 <= price) {
        out = true;
        message::write(data::level2::message4, player_.pseudo(), plug_.name());

        player_.increaseMoney(-price);

        result::write(data::action::resultNegociate(price));
      } else {
        message::write(data::level2::message3, player_.pseudo(), plug_.name());
      }
    }

    message::write(data::level2::message5, player_.pseudo(), plug_.name());
  }
};

namespace negociate {
template <utils::Printable T, utils::Printable U>
void trigger(entity::Player& player, const entity::Plug& plug, int plugPrice,
             const T& statement, const U& result) {
  Negociate negociate{player, plug, plugPrice, statement, result};
  negociate.trigger();
}
}  // namespace negociate
}  // namespace elevation::action
