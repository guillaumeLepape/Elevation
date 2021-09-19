#ifndef QUESTION_H
#define QUESTION_H

/*!
 * \file Question.h
 */

#include <string>
#include <vector>

#include "NameType.h"

namespace Question {
bool question(const Title& title, const std::vector<std::string>& statements,
              const std::vector<bool>& answers);
}

#endif