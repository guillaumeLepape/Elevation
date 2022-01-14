#include "Negociate.h"

#include <iostream>

#include "Languages.h"
#include "MessageWriter.h"
#include "Pause.h"
#include "Player.h"
#include "Plug.h"

namespace action {
Negociate::Negociate(entity::Player& player, const entity::Plug& plug,
                     const int& plugPrice, const Statement& statement,
                     const Result& result)
    : statement_{statement},
      result_{result},
      player_{player},
      plug_{plug},
      plugPrice_{plugPrice} {}

void Negociate::trigger() {
  bool out = false;

  Message::write(data::Level2::message1, player_.pseudo(), plug_.name());

  while (not out) {
    action::writeStatement(statement_);

    int price;
    std::cin >> price;

    while (true) {
      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "\n " << Term::color(Term::bg::red)
                  << Term::color(Term::style::bold) << "Entrez le prix valide."
                  << Term::color(Term::bg::reset)
                  << Term::color(Term::style::reset);

        utils::pause();

        action::writeStatement(statement_);
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

      action::writeResult(data::Action::resultNegociate(price));
    } else {
      Message::write(data::Level2::message3, player_.pseudo(), plug_.name());
    }
  }

  Message::write(data::Level2::message5, player_.pseudo(), plug_.name());
}
}  // namespace action