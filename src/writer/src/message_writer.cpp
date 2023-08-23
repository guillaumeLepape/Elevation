#include "message_writer.h"

namespace message {
void write(const MessageWriter& messageWriter) {
  write(messageWriter.messages_, messageWriter.pseudo_,
        messageWriter.plugName_);
}
}  // namespace message
