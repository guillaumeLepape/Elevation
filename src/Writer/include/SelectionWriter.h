#ifndef SELECTION_WRITER_H
#define SELECTION_WRITER_H

/*!
 * \file SelectionWriter.h
 */

#include <string_view>
#include <vector>

#include "NameType.h"
#include "Pause.h"

namespace selection {
void write(const Title& title, const std::vector<std::string>& statements);
}

#endif