#include "elevation/writer/message_writer.h"

namespace elevation::message {
void write(const MessageWriter& messageWriter) {
  write(messageWriter.messages_, messageWriter.pseudo_,
        messageWriter.plugName_);
}
}  // namespace elevation::message
