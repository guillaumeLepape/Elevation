/*!
 * \file MessageWriter.cpp
 */

#include "MessageWriter.h"

#include <cassert>

#include "Pause.h"

namespace Message {
void write(const Message_t& messages, const std::string& pseudo,
           const std::string& plugName) {
  for (const auto& message : messages) {
    utils::pause();

    switch (std::get<0>(message)) {
      case NameSpeaker::player:
        std::cout << "\n        " << Term::color(Term::fg::green)
                  << Term::color(Term::style::bold) << pseudo
                  << Term::color(Term::fg::reset)
                  << Term::color(Term::style::reset);
        std::cout << Term::color(Term::fg::blue)
                  << Term::color(Term::style::bold);
        break;

      case NameSpeaker::plug:
        std::cout << "\n        " << Term::color(Term::fg::red)
                  << Term::color(Term::style::bold) << plugName
                  << Term::color(Term::fg::reset)
                  << Term::color(Term::style::reset);
        std::cout << Term::color(Term::fg::blue)
                  << Term::color(Term::style::bold);
        break;

      case NameSpeaker::description:
        std::cout << Term::color(Term::fg::magenta)
                  << Term::color(Term::style::bold);
        break;

      case NameSpeaker::action:
        std::cout << Term::color(Term::fg::yellow)
                  << Term::color(Term::style::bold);
        break;
    }

    std::cout << "\n " << (std::get<1>(message));
    std::cout << Term::color(Term::fg::reset)
              << Term::color(Term::style::reset);
  }
}

void write(const MessageWriter& messageWriter) {
  write(messageWriter.messages_, messageWriter.pseudo_,
        messageWriter.plugName_);
}
}  // namespace Message
