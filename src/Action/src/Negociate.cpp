/*!
 * \file Negociate.cpp
 */

#include "Negociate.h"

#include <iostream>

#include "Languages.h"
#include "MessageWriter.h"
#include "Pause.h"
#include "Player.h"
#include "Plug.h"

Negociate::Negociate(Player* const player, Plug* const plug,
                     const int& plugPrice, const Statement& statement,
                     const Result& result)
    : statement_(statement),
      result_(result),
      player_(player),
      plug_(plug),
      plugPrice_(plugPrice) {}

void Negociate::triggerAction() {
  bool out = false;

  MessageWriter messageWriter1(data::Level2::message1, player_->name(),
                               plug_->name());
  messageWriter1.writeMessage();

  while (!out) {
    Action::writeStatement(statement_);

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

        Pause::pause();

        Action::writeStatement(statement_);
        std::cin >> price;
      }
      if (!std::cin.fail()) {
        break;
      }
    }

    if (price > plugPrice_) {
      MessageWriter messageWriter2(data::Level2::message2, player_->name(),
                                   plug_->name());
      messageWriter2.writeMessage();
    } else if (price <= plugPrice_ && plugPrice_ - 30 <= price) {
      out = true;
      MessageWriter messageWriter4(data::Level2::message4, player_->name(),
                                   plug_->name());
      messageWriter4.writeMessage();

      player_->increaseMoney(-price);

      Action::writeResult(data::Action::resultNegociate(price));
    } else {
      MessageWriter messageWriter3(data::Level2::message3, player_->name(),
                                   plug_->name());
      messageWriter3.writeMessage();
    }
  }

  MessageWriter messageWriter5(data::Level2::message5, player_->name(),
                               plug_->name());
  messageWriter5.writeMessage();
}