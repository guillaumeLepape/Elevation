#ifndef HEADER_WRITER_H
#define HEADER_WRITER_H

/*!
 * \file HeaderWriter.h
 */

#include <string_view>

#include "NameType.h"

class HeaderWriter {
 private:
  std::string_view nameLevel_;
  Hour hour_;
  Minut minut_;

 public:
  HeaderWriter(const std::string_view& nameLevel, const Hour& hour,
               const Minut& minut);

  void writeHeader() const;
};

#endif