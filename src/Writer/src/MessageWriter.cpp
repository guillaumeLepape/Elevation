/*!
 * \file MessageWriter.cpp
 */

#include "MessageWriter.h"

#include <cassert>

#include "Pause.h"

MessageWriter::MessageWriter(
    const std::vector<std::tuple<NameSpeaker, std::string>>& message,
    const std::string& pseudo, const std::string& plugName)
    : message_(message), pseudo_(pseudo), plugName_(plugName) {}

void MessageWriter::writeName(const int& i) const {
  if (std::get<0>(message_[i]) == NameSpeaker::player) {
    std::cout << "\n        " << Term::color(Term::fg::green)
              << Term::color(Term::style::bold) << pseudo_
              << Term::color(Term::fg::reset)
              << Term::color(Term::style::reset);

    std::cout << Term::color(Term::fg::blue) << Term::color(Term::style::bold);
  } else if (std::get<0>(message_[i]) == NameSpeaker::plug) {
    std::cout << "\n        " << Term::color(Term::fg::red)
              << Term::color(Term::style::bold) << plugName_
              << Term::color(Term::fg::reset)
              << Term::color(Term::style::reset);

    std::cout << Term::color(Term::fg::blue) << Term::color(Term::style::bold);
  } else if (std::get<0>(message_[i]) == NameSpeaker::description) {
    std::cout << Term::color(Term::fg::magenta)
              << Term::color(Term::style::bold);
  } else if (std::get<0>(message_[i]) == NameSpeaker::action) {
    std::cout << Term::color(Term::fg::yellow)
              << Term::color(Term::style::bold);
  } else {
    assert(false);
  }
}

void MessageWriter::writeOneMessage(const int& i) const {
  std::cout << "\n " << (std::get<1>(message_[i]));
  std::cout << Term::color(Term::fg::reset) << Term::color(Term::style::reset);
}

void MessageWriter::writeMessage() const {
  for (long unsigned int i = 0; i < message_.size(); i++) {
    Pause::pause();

    writeName(i);

    writeOneMessage(i);
  }
}
