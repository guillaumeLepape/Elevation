#ifndef MESSAGE_WRITER_H
#define MESSAGE_WRITER_H

#include <string>

#include "languages.h"

struct MessageWriter {
  data::Message_t messages_;
  std::string pseudo_;
  std::string plugName_;

  MessageWriter(const data::Message_t& messages, const std::string& pseudo,
                const std::string& plugName)
      : messages_{messages}, pseudo_{pseudo}, plugName_{plugName} {}
};

namespace message {
void write(const data::Message_t& messages, const std::string& pseudo,
           const std::string& plugName);

void write(const MessageWriter& message);
}  // namespace message

#endif