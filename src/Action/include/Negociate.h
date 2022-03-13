#ifndef NEGOCIATE_H
#define NEGOCIATE_H

#include "ActionWriter.h"
#include "Concept.h"
#include "Languages.h"
#include "MessageWriter.h"
#include "Pause.h"
#include "Player.h"
#include "Plug.h"

namespace action {
template <utils::Printable T, utils::Printable U> class Negociate {
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

    Message::write(data::Level2::message1, player_.pseudo(), plug_.name());

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
        Message::write(data::Level2::message2, player_.pseudo(), plug_.name());
      } else if (price <= plugPrice_ and plugPrice_ - 30 <= price) {
        out = true;
        Message::write(data::Level2::message4, player_.pseudo(), plug_.name());

        player_.increaseMoney(-price);

        result::write(data::Action::resultNegociate(price));
      } else {
        Message::write(data::Level2::message3, player_.pseudo(), plug_.name());
      }
    }

    Message::write(data::Level2::message5, player_.pseudo(), plug_.name());
  }
};
}  // namespace action

#endif