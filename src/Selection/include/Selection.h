#ifndef SELECTION_H
#define SELECTION_H

/*!
 * \file Selection.h
 */

#include <vector>

#include "SelectionWriter.h"

class Select {
 public:
  static int select(const std::string& title,
                    const std::vector<std::string>& statements);
};

#endif