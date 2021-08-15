#ifndef HEADER_WRITER_H
#define HEADER_WRITER_H

/*!
 * \file HeaderWriter.h
 */

#include <string>

class HeaderWriter {
 private:
  std::string nameLevel_;
  int hour_;
  int minut_;

 public:
  HeaderWriter(const std::string& nameLevel, const int& hour, const int& minut);

  void writeHeader() const;
};

#endif