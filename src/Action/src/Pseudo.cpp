/*!
 * \file Pseudo.cpp
 */

#include "Pseudo.h"

#include <iostream>

#include "Languages.h"
#include "ListNameData.h"
#include "MessageWriter.h"
#include "Player.h"

Pseudo::Pseudo(Player* const player, const Statement& statement,
               const Result& result)
    : actionWriter_(statement.get(), result.get()), player_(player) {}

void Pseudo::triggerAction() {
  ListNameData feminineNameData("dataset", "prenoms_feminins");
  std::set<std::string> feminineName = feminineNameData.listName();

  ListNameData masculineNameData("dataset", "prenoms_masculins");
  std::set<std::string> masculineName = masculineNameData.listName();

  std::string* ptrPseudo(0);
  bool out = false;

  while (!out) {
    // Inform the user that he have to enter an information (his pseudo)
    MessageWriter messageWriter(data::Introduction::message1, player_->name(),
                                "");
    messageWriter.writeMessage();
    actionWriter_.writeStatement();

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
      MessageWriter messageWriter2(data::Introduction::message2,
                                   player_->name(), "");
      messageWriter2.writeMessage();
    }
    // If pseudo doesn't appear in the two previous dataset,
    // consider that this name doesn't exist
    else {
      MessageWriter messageWriter3(data::Introduction::message3,
                                   player_->name(), "");
      messageWriter3.writeMessage();
    }
  }

  player_->changeName(*ptrPseudo);

  actionWriter_.updateResult(data::Action::resultPseudo(player_->name()).get());
  actionWriter_.writeResult();
}

void Pseudo::formatString(std::string& str) {
  str[0] = std::toupper(str[0]);
  for (long unsigned int i = 1; i < str.length(); i++) {
    str[i] = std::tolower(str[i]);
  }
}