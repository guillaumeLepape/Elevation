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
  ListNameData feminineNameData("dataset", "prenoms_feminins");
  std::set<std::string> feminineName = feminineNameData.listName();

  ListNameData masculineNameData("dataset", "prenoms_masculins");
  std::set<std::string> masculineName = masculineNameData.listName();

  std::string* ptrPseudo(0);
  bool out = false;

  while (!out) {
    // Inform the user that he have to enter an information (his pseudo)
    Message::write(data::Introduction::message1, player_.name(), "");
    Action::writeStatement(statement_);

    // Get pseudo from user
    std::string pseudo;
    std::cin >> pseudo;
    formatString(pseudo);
    ptrPseudo = &pseudo;

    // Check if chosen pseudo is in the feminine name dataset
    if (feminineName.find(pseudo) != feminineName.end()) {
      out = true;
    }
    // Check if chosen pseudo is in the masculine name dataset
    else if (masculineName.find(pseudo) != masculineName.end()) {
      Message::write(data::Introduction::message2, player_.name(), "");
    }
    // If pseudo doesn't appear in the two previous dataset,
    // consider that this name doesn't exist
    else {
      Message::write(data::Introduction::message3, player_.name(), "");
    }
  }

  player_.changeName(*ptrPseudo);

  Action::writeResult(data::Action::resultPseudo(player_.name()));
}

void Pseudo::formatString(std::string& str) {
  str[0] = std::toupper(str[0]);
  for (long unsigned int i = 1; i < str.length(); i++) {
    str[i] = std::tolower(str[i]);
  }
}