#include "MessageWriter.h"

#include <fmt/color.h>

#include "Pause.h"

namespace Message {
void write(const Message_t& messages, const std::string& pseudo,
           const std::string& plugName) {
  for (const auto& message : messages) {
    utils::pause();

    switch (std::get<0>(message)) {
    case NameSpeaker::player:
      fmt::print(fg(fmt::color::green) | fmt::emphasis::bold, "\n        {}",
                 pseudo);
      fmt::print(fg(fmt::color::blue) | fmt::emphasis::bold, "\n {}",
                 std::get<1>(message));
      break;

    case NameSpeaker::plug:
      fmt::print(fg(fmt::color::red) | fmt::emphasis::bold, "\n        {}",
                 plugName);
      fmt::print(fg(fmt::color::blue) | fmt::emphasis::bold, "\n {}",
                 std::get<1>(message));
      break;

    case NameSpeaker::description:
      fmt::print(fg(fmt::color::magenta) | fmt::emphasis::bold, "\n {}",
                 std::get<1>(message));
      break;

    case NameSpeaker::action:
      fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold, "\n {}",
                 std::get<1>(message));
      break;
    }
  }
}

void write(const MessageWriter& messageWriter) {
  write(messageWriter.messages_, messageWriter.pseudo_,
        messageWriter.plugName_);
}
}  // namespace Message
