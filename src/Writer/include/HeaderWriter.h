#ifndef HEADER_WRITER_H
#define HEADER_WRITER_H

/*!
 * \file HeaderWriter.h
 */

#include <string_view>

#include "NameType.h"

namespace Header {
void write(const std::string_view&, const Hour& hour, const Minut& minut);
}

#endif