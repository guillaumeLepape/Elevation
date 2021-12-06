/*!
 * \file Pseudo.cpp
 */

#include "Pseudo.h"

#include <iostream>

#include "Languages.h"
#include "ListNameData.h"
#include "MessageWriter.h"
#include "Player.h"

Pseudo::Pseudo(Player& player, const Statement& statement, const Result& result)
    : statement_(statement), result_(result), player_(player) {}

void Pseudo::triggerAction() {
  auto feminineName = data::read_list_name("dataset", "prenoms_feminins");
  auto masculineName = data::read_list_name("dataset", "prenoms_masculins");

  std::string pseudo;
  bool out = false;

  while (!out) {
    // Inform the user that he have to enter an information (his pseudo)
    Message::write(data::Introduction::message1, player_.pseudo(), "");
    Action::writeStatement(statement_);

    std::cin >> pseudo;
    formatString(pseudo);

    // Check if chosen pseudo is in the feminine name dataset
    if (feminineName.find(pseudo) != std::cend(feminineName)) {
      out = true;
    }
    // Check if chosen pseudo is in the masculine name dataset
    else if (masculineName.find(pseudo) != std::cend(masculineName)) {
      Message::write(data::Introduction::message2, player_.pseudo(), "");
    }
    // If pseudo doesn't appear in the two previous dataset,
    // consider that this name doesn't exist
    else {
      Message::write(data::Introduction::message3, player_.pseudo(), "");
    }
  }

  player_.changePseudo(pseudo);

  Action::writeResult(data::Action::resultPseudo(player_.pseudo()));
}

void Pseudo::formatString(std::string& str) {
  str[0] = std::toupper(str[0]);
  for (long unsigned int i = 1; i < str.length(); i++) {
    str[i] = std::tolower(str[i]);
  }
}