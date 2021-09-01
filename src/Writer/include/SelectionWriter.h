#ifndef SELECTION_WRITER_H
#define SELECTION_WRITER_H

/*!
 * \file SelectionWriter.h
 */

#include <string_view>
#include <vector>

#include "Pause.h"

namespace Selection {
void write(const std::string& title,
           const std::vector<std::string>& statements);
}

#endif