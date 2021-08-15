#ifndef MESSAGE_WRITER_H
#define MESSAGE_WRITER_H

/*!
 * \file MessageWriter.h
 */

#include <string>

#include "NameSpeaker.h"

class MessageWriter {
 private:
  Message message_;
  std::string pseudo_;
  std::string plugName_;

  void writeName(const int& i) const;

  void writeOneMessage(const int& i) const;

 public:
  MessageWriter(
      const std::vector<std::tuple<NameSpeaker, std::string>>& message,
      const std::string& pseudo, const std::string& plugName);

  void writeMessage() const;
};

#endif