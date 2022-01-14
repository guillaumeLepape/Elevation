#ifndef TUTORIAL_WRITER_H
#define TUTORIAL_WRITER_H

#include <string>
#include <vector>

#include "NameType.h"

namespace Tutorial {
void write(const Title& title,
           const std::vector<std::string>& tutorialStatement);
}

#endif