#ifndef PSEUDO_H
#define PSEUDO_H

#include <range/v3/algorithm/binary_search.hpp>

#include "action_writer.h"
#include "concept.h"
#include "languages.h"
#include "list_name_data.h"
#include "message_writer.h"
#include "player.h"

namespace action {
template <utils::Printable T, utils::Printable U>
class Pseudo {
 private:
  T statement_;
  U result_;

  entity::Player& player_;

  void formatString(std::string& str) {
    str[0] = std::toupper(str[0]);
    for (std::size_t i = 1; i < str.length(); i++) {
      str[i] = std::tolower(str[i]);
    }
  }

 public:
  explicit Pseudo(entity::Player& player, const T& statement, const U& result)
      : statement_{statement}, result_{result}, player_{player} {}

  void trigger() {
    const auto feminineName = data::read_list_name("dataset/prenoms_feminins");
    const auto masculineName =
        data::read_list_name("dataset/prenoms_masculins");

    std::string pseudo;
    bool out = false;

    while (not out) {
      // Inform the user that he have to enter an information (his pseudo)
      message::write(data::introduction::message1, player_.pseudo(), "");
      statement::write(statement_);

      std::cin >> pseudo;
      formatString(pseudo);

      // Check if chosen pseudo is in the feminine name dataset
      if (ranges::binary_search(feminineName, pseudo)) {
        out = true;
      }
      // Check if chosen pseudo is in the masculine name dataset
      else if (ranges::binary_search(masculineName, pseudo)) {
        message::write(data::introduction::message2, player_.pseudo(), "");
      }
      // If pseudo doesn't appear in the two previous dataset,
      // consider that this name doesn't exist
      else {
        message::write(data::introduction::message3, player_.pseudo(), "");
      }
    }

    player_.changePseudo(pseudo);

    result::write(data::action::resultPseudo(player_.pseudo()));
  }
};

namespace pseudo {
template <utils::Printable T, utils::Printable U>
void trigger(entity::Player& player, const T& statement, const U& result) {
  Pseudo pseudo{player, statement, result};
  pseudo.trigger();
}
}  // namespace pseudo
}  // namespace action

#endif
