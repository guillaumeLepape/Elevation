#ifndef SELECTION_H
#define SELECTION_H

/*!
 * \file Selection.h
 */

#include <vector>

#include "SelectionWriter.h"

namespace selection {
std::size_t select(const Title& title,
                   const std::vector<std::string>& statements);
}

#endif