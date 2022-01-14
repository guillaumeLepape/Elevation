#ifndef ACTION_WRITER_H
#define ACTION_WRITER_H

#include <string>

#include "NameType.h"

namespace action {
void writeStatement(const Statement& statement);
void writeResult(const Result& result);
}  // namespace action

#endif