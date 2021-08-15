#ifndef SELECTION_H
#define SELECTION_H

/*!
 * \file Selection.h
 */

#include "SelectionWriter.h"

class Selection {
 public:
  static int select(const std::vector<Action*>& actions,
                    const std::string& title);
};

#endif